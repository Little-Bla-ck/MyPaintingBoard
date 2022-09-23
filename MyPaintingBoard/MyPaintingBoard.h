#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyPaintingBoard.h"
#include <qlabel.h>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include "Graphics.h"
#include "MyGraphicsScene.h"
#include "SceneOriginator.h"
#include <qcolordialog.h>

class MyPaintingBoard : public QMainWindow
{
    Q_OBJECT

public:
    MyPaintingBoard(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyPaintingBoardClass ui;

    void initGraphics();

    std::vector<std::string> enum_text = {
        "线条", "三角形", "矩形", "椭圆", "文本"
    };

    SceneOriginator* originator = new SceneOriginator();

    QLabel* labSceneCord;
    QLabel* xViewCord;
    QLabel* yViewCord;
    QLabel* valueLabel;

    QGraphicsScene* scene;
    MyGraphicsScene* myScene;

    QPen pen;
    QBrush brush = QBrush(Qt::SolidPattern);
    QBrush bucketBrush = QBrush(Qt::SolidPattern);

    QPointF clickedPoint;
    bool isClicked = false;
    bool isSelected = false;
    bool isRangeSelected = false;
    bool isPadding = false;

    bool isLineEditDirty = false;

    QGraphicsItem* tempItem = nullptr;
    QGraphicsItem* actualItem = nullptr;
    QPolygonF tempPolygon;
    QPolygonF actrualPolygon;

    enum ValueGraphics currentValue = Line;

    void setColor();

    void setValue();

    void setMemento();

public slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseClickedPoint(QPoint point);
    void on_mouseReleasedPoint(QPoint point);
    void on_mouseDoubleClickedPoint(QPoint point);
    void on_lineTool_triggered();
    void on_rectTool_triggered();
    void on_ellipseTool_triggered();
    void on_textTool_triggered();
    void colorButton_triggered();
    void backgroundColorButton_triggered();
    void bucketColorSet_triggered();
    void on_moveTool_triggered();
    void on_seletedTool_triggered();
    void on_lineEdit_triggered();
    void on_triangleTool_triggered();
    void on_groupTool_triggered();
    void on_unGroupTool_triggered();
    void on_padding_triggered();
    void on_copyItems_triggered();
    void on_roolback_triggered();
};
