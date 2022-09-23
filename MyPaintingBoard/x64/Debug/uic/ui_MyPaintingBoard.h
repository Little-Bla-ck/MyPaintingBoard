/********************************************************************************
** Form generated from reading UI file 'MyPaintingBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPAINTINGBOARD_H
#define UI_MYPAINTINGBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MyPaintingBoardClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *pageSetting;
    QAction *createTool;
    QAction *saveTool;
    QAction *openTool;
    QAction *lineTool;
    QAction *rectTool;
    QAction *ellipseTool;
    QAction *triangleTool;
    QAction *textTool;
    QAction *paddingTool;
    QAction *moveTool;
    QAction *selectTool;
    QAction *magnifyTool;
    QAction *shrinkTool;
    QAction *commitTool;
    QAction *rollbackTool;
    QAction *testRect;
    QAction *groupTool;
    QAction *unGroupTool;
    QAction *copyItems;
    QAction *pasteItems;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    MyGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *colorLabel;
    QLabel *bucketColor;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *colorSetButton;
    QPushButton *backgroundColorButton;
    QPushButton *bucketColorSet;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineWidth;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_3;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyPaintingBoardClass)
    {
        if (MyPaintingBoardClass->objectName().isEmpty())
            MyPaintingBoardClass->setObjectName(QStringLiteral("MyPaintingBoardClass"));
        MyPaintingBoardClass->resize(1920, 1080);
        actionOpen = new QAction(MyPaintingBoardClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MyPaintingBoardClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        pageSetting = new QAction(MyPaintingBoardClass);
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        createTool = new QAction(MyPaintingBoardClass);
        createTool->setObjectName(QStringLiteral("createTool"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\346\226\260\345\273\272\351\242\234\350\211\262_\345\233\276\345\261\202.png"), QSize(), QIcon::Normal, QIcon::Off);
        createTool->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        createTool->setFont(font);
        saveTool = new QAction(MyPaintingBoardClass);
        saveTool->setObjectName(QStringLiteral("saveTool"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveTool->setIcon(icon1);
        saveTool->setFont(font);
        openTool = new QAction(MyPaintingBoardClass);
        openTool->setObjectName(QStringLiteral("openTool"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        openTool->setIcon(icon2);
        openTool->setFont(font);
        lineTool = new QAction(MyPaintingBoardClass);
        lineTool->setObjectName(QStringLiteral("lineTool"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\233\276\345\275\242-\347\233\264\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineTool->setIcon(icon3);
        lineTool->setFont(font);
        rectTool = new QAction(MyPaintingBoardClass);
        rectTool->setObjectName(QStringLiteral("rectTool"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\233\276\345\275\242-\347\237\251\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectTool->setIcon(icon4);
        rectTool->setFont(font);
        ellipseTool = new QAction(MyPaintingBoardClass);
        ellipseTool->setObjectName(QStringLiteral("ellipseTool"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\233\276\345\275\242-\345\234\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipseTool->setIcon(icon5);
        ellipseTool->setFont(font);
        triangleTool = new QAction(MyPaintingBoardClass);
        triangleTool->setObjectName(QStringLiteral("triangleTool"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\275\242\347\212\266-\344\270\211\350\247\222\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleTool->setIcon(icon6);
        triangleTool->setFont(font);
        textTool = new QAction(MyPaintingBoardClass);
        textTool->setObjectName(QStringLiteral("textTool"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\346\226\207\345\255\227.png"), QSize(), QIcon::Normal, QIcon::Off);
        textTool->setIcon(icon7);
        textTool->setFont(font);
        paddingTool = new QAction(MyPaintingBoardClass);
        paddingTool->setObjectName(QStringLiteral("paddingTool"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\346\262\271\346\274\206\346\241\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        paddingTool->setIcon(icon8);
        paddingTool->setFont(font);
        moveTool = new QAction(MyPaintingBoardClass);
        moveTool->setObjectName(QStringLiteral("moveTool"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\347\247\273\345\212\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveTool->setIcon(icon9);
        moveTool->setFont(font);
        selectTool = new QAction(MyPaintingBoardClass);
        selectTool->setObjectName(QStringLiteral("selectTool"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\351\200\211\345\214\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectTool->setIcon(icon10);
        selectTool->setFont(font);
        magnifyTool = new QAction(MyPaintingBoardClass);
        magnifyTool->setObjectName(QStringLiteral("magnifyTool"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\346\224\276\345\244\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        magnifyTool->setIcon(icon11);
        magnifyTool->setFont(font);
        shrinkTool = new QAction(MyPaintingBoardClass);
        shrinkTool->setObjectName(QStringLiteral("shrinkTool"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\347\274\251\345\260\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        shrinkTool->setIcon(icon12);
        shrinkTool->setFont(font);
        commitTool = new QAction(MyPaintingBoardClass);
        commitTool->setObjectName(QStringLiteral("commitTool"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\220\216\351\200\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        commitTool->setIcon(icon13);
        commitTool->setFont(font);
        rollbackTool = new QAction(MyPaintingBoardClass);
        rollbackTool->setObjectName(QStringLiteral("rollbackTool"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\345\211\215\350\277\233.png"), QSize(), QIcon::Normal, QIcon::Off);
        rollbackTool->setIcon(icon14);
        rollbackTool->setFont(font);
        testRect = new QAction(MyPaintingBoardClass);
        testRect->setObjectName(QStringLiteral("testRect"));
        groupTool = new QAction(MyPaintingBoardClass);
        groupTool->setObjectName(QStringLiteral("groupTool"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/MyPaintingBoard/resource/\347\273\204\345\220\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        groupTool->setIcon(icon15);
        groupTool->setFont(font);
        unGroupTool = new QAction(MyPaintingBoardClass);
        unGroupTool->setObjectName(QStringLiteral("unGroupTool"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/MyPaintingBoard/resource/GraphicsGroup.h"), QSize(), QIcon::Normal, QIcon::Off);
        unGroupTool->setIcon(icon16);
        copyItems = new QAction(MyPaintingBoardClass);
        copyItems->setObjectName(QStringLiteral("copyItems"));
        pasteItems = new QAction(MyPaintingBoardClass);
        pasteItems->setObjectName(QStringLiteral("pasteItems"));
        centralWidget = new QWidget(MyPaintingBoardClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new MyGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        colorLabel = new QLabel(widget_6);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));

        horizontalLayout_6->addWidget(colorLabel);

        bucketColor = new QLabel(widget_6);
        bucketColor->setObjectName(QStringLiteral("bucketColor"));

        horizontalLayout_6->addWidget(bucketColor);

        colorLabel->raise();
        colorLabel->raise();
        bucketColor->raise();

        verticalLayout_2->addWidget(widget_6);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        colorSetButton = new QPushButton(widget_5);
        colorSetButton->setObjectName(QStringLiteral("colorSetButton"));
        colorSetButton->setFont(font);

        horizontalLayout_5->addWidget(colorSetButton);

        backgroundColorButton = new QPushButton(widget_5);
        backgroundColorButton->setObjectName(QStringLiteral("backgroundColorButton"));
        backgroundColorButton->setFont(font);

        horizontalLayout_5->addWidget(backgroundColorButton);

        bucketColorSet = new QPushButton(widget_5);
        bucketColorSet->setObjectName(QStringLiteral("bucketColorSet"));
        bucketColorSet->setFont(font);

        horizontalLayout_5->addWidget(bucketColorSet);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 2);

        verticalLayout_2->addWidget(widget_5);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineWidth = new QLineEdit(widget_2);
        lineWidth->setObjectName(QStringLiteral("lineWidth"));
        lineWidth->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(lineWidth);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        lineEdit_3 = new QLineEdit(widget_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout_2->addWidget(widget_4);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 6);

        horizontalLayout->addWidget(widget);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        MyPaintingBoardClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyPaintingBoardClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1920, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MyPaintingBoardClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyPaintingBoardClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MyPaintingBoardClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyPaintingBoardClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPaintingBoardClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(pageSetting);
        mainToolBar->addAction(createTool);
        mainToolBar->addAction(openTool);
        mainToolBar->addAction(saveTool);
        mainToolBar->addAction(moveTool);
        mainToolBar->addAction(selectTool);
        mainToolBar->addAction(lineTool);
        mainToolBar->addAction(rectTool);
        mainToolBar->addAction(ellipseTool);
        mainToolBar->addAction(triangleTool);
        mainToolBar->addAction(textTool);
        mainToolBar->addAction(paddingTool);
        mainToolBar->addAction(groupTool);
        mainToolBar->addAction(unGroupTool);
        mainToolBar->addAction(magnifyTool);
        mainToolBar->addAction(shrinkTool);
        mainToolBar->addAction(commitTool);
        mainToolBar->addAction(rollbackTool);
        mainToolBar->addAction(copyItems);

        retranslateUi(MyPaintingBoardClass);

        QMetaObject::connectSlotsByName(MyPaintingBoardClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPaintingBoardClass)
    {
        MyPaintingBoardClass->setWindowTitle(QApplication::translate("MyPaintingBoardClass", "MyPaintingBoard", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MyPaintingBoardClass", "\346\211\223\345\274\200\351\241\271\347\233\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MyPaintingBoardClass", "\346\223\215\344\275\234\344\273\245\346\211\223\345\274\200\347\216\260\346\234\211\351\241\271\347\233\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MyPaintingBoardClass", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MyPaintingBoardClass", "\344\277\235\345\255\230", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MyPaintingBoardClass", "\346\223\215\344\275\234\344\273\245\344\277\235\345\255\230\345\275\223\345\211\215\351\241\271\347\233\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MyPaintingBoardClass", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pageSetting->setText(QApplication::translate("MyPaintingBoardClass", "\351\241\265\351\235\242\350\256\276\347\275\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pageSetting->setToolTip(QApplication::translate("MyPaintingBoardClass", "\346\223\215\344\275\234\344\273\245\350\256\276\347\275\256\351\241\265\351\235\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\226\260\345\273\272\346\226\207\344\273\266", Q_NULLPTR));
        saveTool->setText(QApplication::translate("MyPaintingBoardClass", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        openTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        lineTool->setText(QApplication::translate("MyPaintingBoardClass", "\347\233\264\347\272\277", Q_NULLPTR));
        rectTool->setText(QApplication::translate("MyPaintingBoardClass", "\347\237\251\345\275\242", Q_NULLPTR));
        ellipseTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\244\255\345\234\206", Q_NULLPTR));
        triangleTool->setText(QApplication::translate("MyPaintingBoardClass", "\344\270\211\350\247\222\345\275\242", Q_NULLPTR));
        textTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\226\207\345\255\227", Q_NULLPTR));
        paddingTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\262\271\346\274\206\346\241\266", Q_NULLPTR));
        moveTool->setText(QApplication::translate("MyPaintingBoardClass", "\347\247\273\345\212\250", Q_NULLPTR));
        selectTool->setText(QApplication::translate("MyPaintingBoardClass", "\351\200\211\346\213\251", Q_NULLPTR));
        magnifyTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\224\276\345\244\247", Q_NULLPTR));
        shrinkTool->setText(QApplication::translate("MyPaintingBoardClass", "\347\274\251\345\260\217", Q_NULLPTR));
        commitTool->setText(QApplication::translate("MyPaintingBoardClass", "\345\211\215\350\277\233", Q_NULLPTR));
        rollbackTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\222\244\351\224\200", Q_NULLPTR));
        testRect->setText(QApplication::translate("MyPaintingBoardClass", "1", Q_NULLPTR));
        groupTool->setText(QApplication::translate("MyPaintingBoardClass", "\347\273\204\345\220\210", Q_NULLPTR));
        unGroupTool->setText(QApplication::translate("MyPaintingBoardClass", "\346\211\223\346\225\243", Q_NULLPTR));
        copyItems->setText(QApplication::translate("MyPaintingBoardClass", "\345\244\215\345\210\266", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        copyItems->setShortcut(QApplication::translate("MyPaintingBoardClass", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pasteItems->setText(QApplication::translate("MyPaintingBoardClass", "\347\262\230\350\264\264", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        pasteItems->setShortcut(QApplication::translate("MyPaintingBoardClass", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        colorLabel->setText(QString());
        bucketColor->setText(QString());
        colorSetButton->setText(QApplication::translate("MyPaintingBoardClass", "\350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262", Q_NULLPTR));
        backgroundColorButton->setText(QApplication::translate("MyPaintingBoardClass", "\350\256\276\347\275\256\345\241\253\345\205\205\351\242\234\350\211\262", Q_NULLPTR));
        bucketColorSet->setText(QApplication::translate("MyPaintingBoardClass", "\350\256\276\347\275\256\346\262\271\346\274\206\346\241\266\351\242\234\350\211\262", Q_NULLPTR));
        label->setText(QApplication::translate("MyPaintingBoardClass", "\347\272\277\346\235\241\345\256\275\345\272\246:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MyPaintingBoardClass", "\351\225\277\345\272\246:   ", Q_NULLPTR));
        label_4->setText(QApplication::translate("MyPaintingBoardClass", "\345\256\275\345\272\246\357\274\232", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MyPaintingBoardClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyPaintingBoardClass: public Ui_MyPaintingBoardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPAINTINGBOARD_H
