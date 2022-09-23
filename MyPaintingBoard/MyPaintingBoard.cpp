#pragma execution_character_set("utf-8")
#include "MyPaintingBoard.h"
#include <qpoint.h>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <qpen.h>
#include "GraphicsFactory.h"
#include "AbstractGraphicsFactory.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcolordialog.h>
#include <qinputdialog.h>
#include <qfontdialog.h>
#include <qvector.h>
#include <qwidget.h>
#include <qfile.h>

MyPaintingBoard::MyPaintingBoard(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    labSceneCord = new QLabel("场景坐标：");
    labSceneCord->setMinimumWidth(150);
    ui.statusBar->addWidget(labSceneCord);
    xViewCord = new QLabel("");
    xViewCord->setMinimumWidth(150);
    ui.statusBar->addWidget(xViewCord);
    yViewCord = new QLabel("");
    yViewCord->setMinimumWidth(150);
    ui.statusBar->addWidget(yViewCord);

    char tempChar[10];
    strcpy(tempChar, enum_text[currentValue].c_str());
    valueLabel = new QLabel(tempChar);
    valueLabel->setMinimumWidth(150);
    ui.statusBar->addWidget(valueLabel);

    ui.graphicsView->setCursor(Qt::CrossCursor);
    ui.graphicsView->setMouseTracking(true);
    initGraphics();

    connect(ui.graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(on_mouseMovePoint(QPoint)));

    connect(ui.graphicsView, SIGNAL(mouseClicked(QPoint)), this, SLOT(on_mouseClickedPoint(QPoint)));

    connect(ui.graphicsView, SIGNAL(mouseReleased(QPoint)), this, SLOT(on_mouseReleasedPoint(QPoint)));

    connect(ui.graphicsView, SIGNAL(mouseDoubleClicked(QPoint)), this, SLOT(on_mouseDoubleClickedPoint(QPoint)));

    connect(ui.lineTool, SIGNAL(triggered()), this, SLOT(on_lineTool_triggered()));

    connect(ui.rectTool, SIGNAL(triggered()), this, SLOT(on_rectTool_triggered()));

    connect(ui.colorSetButton, SIGNAL(clicked()), this, SLOT(colorButton_triggered()));

    connect(ui.backgroundColorButton, SIGNAL(clicked()), this, SLOT(backgroundColorButton_triggered()));

    connect(ui.bucketColorSet, SIGNAL(clicked()), this, SLOT(bucketColorSet_triggered()));

    connect(ui.moveTool, SIGNAL(triggered()), this, SLOT(on_moveTool_triggered()));

    connect(ui.selectTool, SIGNAL(triggered()), this, SLOT(on_seletedTool_triggered()));

    connect(ui.lineWidth, SIGNAL(editingFinished()), this, SLOT(on_lineEdit_triggered()));

    connect(ui.textTool, SIGNAL(triggered()), this, SLOT(on_textTool_triggered()));

    connect(ui.triangleTool, SIGNAL(triggered()), this, SLOT(on_triangleTool_triggered()));

    connect(ui.unGroupTool, SIGNAL(triggered()), this, SLOT(on_unGroupTool_triggered()));

    connect(ui.paddingTool, SIGNAL(triggered()), this, SLOT(on_padding_triggered()));

    connect(ui.rollbackTool, SIGNAL(triggered()), this, SLOT(on_roolback_triggered()));
}

void MyPaintingBoard::initGraphics()
{
    QRectF rect(-200, -100, 400, 200);


    scene = new QGraphicsScene(rect);


    ui.graphicsView->setScene(scene);
    myScene = new MyGraphicsScene(scene);


    brush.setColor(Qt::white);
    bucketBrush.setColor(Qt::white);
    pen.setWidth(3);
    ui.lineWidth->setText(QString::asprintf("%d", pen.width()));
    setColor();
    ui.bucketColor->setStyleSheet(QString::asprintf("QLabel{background-color:rgb(%d, %d, %d);}", bucketBrush.color().red(), bucketBrush.color().green(), bucketBrush.color().blue()));

    //itemEllipse2 = new QGraphicsEllipseItem(-50, -50, 50, 50);
    //itemEllipse2->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    //itemEllipse2->setPos(0, 5);
    //itemEllipse2->setBrush(QBrush(Qt::green));
    //scene->addItem(itemEllipse2);
    //QWidget* itemWidget = new QWidget(ui.widget);
    //QVBoxLayout* itemLayout = new QVBoxLayout(itemWidget);
    //QLabel* test = new QLabel("1");
}

void MyPaintingBoard::on_mouseMovePoint(QPoint point)
{
    QPointF pointScene = ui.graphicsView->mapToScene(point);

    if (tempItem != nullptr) {
        delete tempItem;
        scene->update();
    }
    tempItem = actualItem;
    QPen tempPen;
    tempPen.setStyle(Qt::DashLine);
    if (isSelected) {
        return;
    }
    switch (currentValue) {
    case Line:
        if (isClicked) {
            actualItem = scene->addLine(clickedPoint.x(), clickedPoint.y(), pointScene.x(), pointScene.y(), tempPen);
        }
        break;
    
    case Rectangle:
        if (isClicked) {
            actualItem = scene->addRect(clickedPoint.x(), clickedPoint.y(), pointScene.x() - clickedPoint.x(), pointScene.y() - clickedPoint.y(), tempPen);
        }
        break;

    case Ellipse:
        if (isClicked) {
            actualItem = scene->addEllipse(clickedPoint.x(), clickedPoint.y(), pointScene.x() - clickedPoint.x(), pointScene.y() - clickedPoint.y(), tempPen);
        }
        break;

    case Triangle:
        if (isClicked) {
            QVector<QPointF> polygonPoints;
            polygonPoints.append(QPointF(clickedPoint.x(), pointScene.y()));
            polygonPoints.append(QPointF((clickedPoint.x() + pointScene.x()) / 2, clickedPoint.y()));
            polygonPoints.append(QPointF(pointScene.x(), pointScene.y()));
            actualItem = scene->addPolygon(QPolygonF(polygonPoints), tempPen);
        }
        break;
    }

    

    scene->update();
    tempItem = actualItem;
    labSceneCord->setText(QString::asprintf("场景坐标：%.0f, %.0f", pointScene.x(), pointScene.y()));
    if (isClicked) {
        xViewCord->setText(QString::asprintf("横向坐标差：%.0f", abs(pointScene.x() - clickedPoint.x())));
        yViewCord->setText(QString::asprintf("纵向坐标差：%.0f", abs(pointScene.y() - clickedPoint.y())));
    }
    
}

void MyPaintingBoard::on_mouseClickedPoint(QPoint point)
{
    clickedPoint = ui.graphicsView->mapToScene(point);
    // 保存点击点
    if (isSelected || isRangeSelected) {
        return;
    }
    if (isPadding) { //油漆桶
        auto pointItem = scene->itemAt(clickedPoint, ui.graphicsView->transform());

        if (pointItem == NULL) {
            return;
        }
        switch (pointItem->type()) {
        case QGraphicsRectItem::Type: {
            auto rectTemp = qgraphicsitem_cast<QGraphicsRectItem*>(pointItem);
            rectTemp->setBrush(bucketBrush);
            break;
        }
        case QGraphicsEllipseItem ::Type: {
            auto rectTemp = qgraphicsitem_cast<QGraphicsEllipseItem*>(pointItem);
            rectTemp->setBrush(bucketBrush);
            break;
        }
        case QGraphicsPolygonItem::Type: {
            auto rectTemp = qgraphicsitem_cast<QGraphicsPolygonItem*>(pointItem);
            rectTemp->setBrush(bucketBrush);
            break;
        }
        default:
            break;
        }
        return;
    }


    isClicked = true;
    myScene->setSelected(isSelected || isRangeSelected);
    if (!isRangeSelected) {
        ui.graphicsView->setDragMode(QGraphicsView::NoDrag);
    }
}

void MyPaintingBoard::on_mouseReleasedPoint(QPoint point)
{
    if (isSelected || isRangeSelected || isPadding) {
        return;
    }
    QPointF pointScene = ui.graphicsView->mapToScene(point);
    
    delete tempItem;
    isClicked = false;
    tempItem = nullptr;
    
    // 清空temp指针
    // 保存要添加的图形
    switch (currentValue) {
    case Line:
        myScene->addLine(clickedPoint, pointScene, pen, brush);
        break;

    case Rectangle:
        myScene->addRect(clickedPoint, pointScene, pen, brush);
        break;
    
    case Ellipse:
        myScene->addEllipse(clickedPoint, pointScene, pen, brush);
        break;

    case Text: {
        if (scene->itemAt(pointScene, ui.graphicsView->transform()) != NULL && scene->itemAt(pointScene, ui.graphicsView->transform())->type() == QGraphicsTextItem::Type) {
            return;
        }
        QInputDialog textInput;
        QString text = textInput.getText(ui.centralWidget, "设置文字", "设置文字", QLineEdit::Normal, NULL, NULL, 0, 0);
        QFontDialog fontInput;
        bool textFlag = true;
        QFont font = fontInput.getFont(&textFlag, ui.centralWidget);
        myScene->addText(pointScene, font, text);
        break; 
    }

    case Triangle: {
        QVector<QPointF> polygonPoints;
        polygonPoints.append(QPointF(clickedPoint.x(), pointScene.y()));
        polygonPoints.append(QPointF((clickedPoint.x() + pointScene.x()) / 2, clickedPoint.y()));
        polygonPoints.append(QPointF(pointScene.x(), pointScene.y()));
        myScene->addTriangle(polygonPoints, pen, brush);
        break;
    }
    }
    actualItem = nullptr;
    xViewCord->setText("");
    yViewCord->setText("");
    scene->update();
}

void MyPaintingBoard::on_mouseDoubleClickedPoint(QPoint point) {
    QPointF pointScene = ui.graphicsView->mapToScene(point); 
    auto pointItem = scene->itemAt(pointScene, ui.graphicsView->transform());

    if (pointItem == NULL) {
        return;
    }

    switch (pointItem->type()) {
    case QGraphicsRectItem::Type: {
        QInputDialog inputDiaglog;
        QGraphicsRectItem* pointRectItem;
        pointRectItem = qgraphicsitem_cast<QGraphicsRectItem*>(pointItem);

        QPen rectPen(pen);
        rectPen.setWidth(inputDiaglog.getInt(ui.centralWidget, "设置线条宽度", "设置线条宽度", pen.width(), 0, 100, 1, nullptr));

        pointRectItem->setPen(rectPen);
        scene->update();
        break;
    }
    case QGraphicsEllipseItem::Type: {
        QInputDialog inputDiaglog;
        QGraphicsEllipseItem* pointEllipseItem;
        pointEllipseItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(pointItem);

        QPen rectPen(pen);
        rectPen.setWidth(inputDiaglog.getInt(ui.centralWidget, "设置线条宽度", "设置线条宽度", pen.width(), 0, 100, 1, nullptr));

        pointEllipseItem->setPen(rectPen);
        scene->update();
        break;
    }
    case QGraphicsLineItem::Type: {
        QInputDialog inputDiaglog;
        QGraphicsLineItem* pointLineItem;
        pointLineItem = qgraphicsitem_cast<QGraphicsLineItem*>(pointItem);

        QPen rectPen(pen);
        rectPen.setWidth(inputDiaglog.getInt(ui.centralWidget, "设置线条宽度", "设置线条宽度", pen.width(), 0, 100, 1, nullptr));

        pointLineItem->setPen(rectPen);
        scene->update();
        break;
    }
    case QGraphicsPolygonItem::Type: {
        QInputDialog inputDiaglog;
        QGraphicsPolygonItem* pointPolygonItem;
        pointPolygonItem = qgraphicsitem_cast<QGraphicsPolygonItem*>(pointItem);

        QPen rectPen(pen);
        rectPen.setWidth(inputDiaglog.getInt(ui.centralWidget, "设置线条宽度", "设置线条宽度", pen.width(), 0, 100, 1, nullptr));

        pointPolygonItem->setPen(rectPen);
        scene->update();
        break;
    }
    }
}


void MyPaintingBoard::on_lineTool_triggered()
{
    isSelected = false;
    isRangeSelected = false;
    isPadding = false;


    currentValue = Line;
    setValue();
}

void MyPaintingBoard::on_rectTool_triggered()
{
    isSelected = false;

    isRangeSelected = false;
    isPadding = false;

    currentValue = Rectangle;
    setValue();
}

void MyPaintingBoard::on_ellipseTool_triggered()
{
    isSelected = false;

    isRangeSelected = false;
    isPadding = false;


    currentValue = Ellipse;

    setValue();
}

void MyPaintingBoard::colorButton_triggered()
{
    QColorDialog* colorDialog = new QColorDialog(this);
    pen.setColor(colorDialog->getColor());
    setColor();
    delete colorDialog;
}

void MyPaintingBoard::backgroundColorButton_triggered() {
    QColorDialog* colorDialog = new QColorDialog(this);
    brush.setColor(colorDialog->getColor());
    setColor();
    delete colorDialog;
}

void MyPaintingBoard::bucketColorSet_triggered()
{
    QColorDialog* colorDialog = new QColorDialog(this);
    bucketBrush.setColor(colorDialog->getColor());
    ui.bucketColor->setStyleSheet(QString::asprintf("QLabel{background-color:rgb(%d, %d, %d);}", bucketBrush.color().red(), bucketBrush.color().green(), bucketBrush.color().blue()));
    delete colorDialog;
}

void MyPaintingBoard::on_moveTool_triggered()
{
    isSelected = true;
    isRangeSelected = false;
    isPadding = false;

    myScene->setSelected(true);
}

void MyPaintingBoard::on_textTool_triggered()
{
    isSelected = false;
    isRangeSelected = false;
    isPadding = false;

    currentValue = Text;
    setValue();
}

void MyPaintingBoard::on_lineEdit_triggered()
{
    pen.setWidth(ui.lineWidth->text().toInt());
    setColor();
}

void MyPaintingBoard::on_triangleTool_triggered()
{
    isSelected = false;

    isRangeSelected = false;

    isPadding = false;

    currentValue = Triangle;

    setValue();
}

void MyPaintingBoard::on_groupTool_triggered()
{
    myScene->addGroup();  
}

void MyPaintingBoard::on_unGroupTool_triggered()
{
    int num = scene->selectedItems().count();
    if (num == 0) {
        return;
    }
    QList<QGraphicsItemGroup*> list;
    
    for (int i = 0; i < num; ++i) {
        auto item = scene->selectedItems().at(0);
        if (item->type() == QGraphicsItemGroup::Type) {
            QGraphicsItemGroup* group = qgraphicsitem_cast<QGraphicsItemGroup*>(item);
            list.append(group);
        }
    }
    for each (auto groupItem in list)
    {
        scene->destroyItemGroup(groupItem);
    }
}

void MyPaintingBoard::on_padding_triggered()
{
    isSelected = false;
    isRangeSelected = false;
    isPadding = true;
}

void MyPaintingBoard::on_copyItems_triggered()
{
    int num = scene->selectedItems().count();
    if (num == 0) {
        return;
    }
    auto itemsList = scene->selectedItems();
    QList<QGraphicsItem*> list;

    for (int i = 0; i < num; ++i) {
        switch (itemsList.at(i)->type())
        {
        case QGraphicsRectItem::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsRectItem*>(itemsList.at(i));
            myScene->addRect(temp);
            break;
        }
        case QGraphicsEllipseItem::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsEllipseItem*>(itemsList.at(i));
            myScene->addEllipse(temp);
            break;
        }
        case QGraphicsPolygonItem::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsPolygonItem*>(itemsList.at(i));
            myScene->addTriangle(temp);
            break;
        }
        case QGraphicsTextItem::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsTextItem*>(itemsList.at(i));
            myScene->addText(temp);
            break;
        }
        case QGraphicsLineItem::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsLineItem*>(itemsList.at(i));
            myScene->addLine(temp);
            break;
        }
        case QGraphicsItemGroup::Type: {
            auto temp = qgraphicsitem_cast<QGraphicsItemGroup*>(itemsList.at(i));
            myScene->addGroup(temp);
            break;
        }
        default:
            break;
        }
        
    }  
    return;
}

void MyPaintingBoard::on_roolback_triggered()
{
    QRectF rect(-200, -100, 400, 200);
    scene = new QGraphicsScene(rect);

    ui.graphicsView->setScene(scene);
    myScene = new MyGraphicsScene(scene);
}

void MyPaintingBoard::setColor() {
    ui.colorLabel->setStyleSheet(QString::asprintf("QLabel{background-color:rgb(%d, %d, %d);border-style: solid; border-width: %dpx; border-color:rgb(%d, %d, %d);}", brush.color().red(), brush.color().green(), brush.color().blue(), pen.width(), pen.color().red(), pen.color().green(), pen.color().blue()));
}

void MyPaintingBoard::setValue()
{
    char tempChar[10];
    strcpy(tempChar, enum_text[currentValue].c_str());
    valueLabel->setText(tempChar);
}

void MyPaintingBoard::setMemento()
{
    originator->createMemeto(myScene);
}

void MyPaintingBoard::on_seletedTool_triggered() {
    isRangeSelected = true;
    isSelected = false;
    isPadding = false;
    myScene->setSelected(true);
    ui.graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
}




