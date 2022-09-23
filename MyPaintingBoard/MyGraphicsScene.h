#pragma once
#include <qgraphicsscene.h>
#include "MyGraphicsScene.h"
#include "GraphicsAggregate.h"
#include "Graphics.h"
#include "GraphicsFactory.h"
#include "qpoint.h"

class MyGraphicsScene
{
private:
    QGraphicsScene* scene;
    GraphicsAggregate* aggregate = new GraphicsAggregate();
    GraphicsFactory* factory = new GraphicsFactory();

public:
    MyGraphicsScene(QGraphicsScene* scene) {
        this->scene = scene;
    }

    MyGraphicsScene(MyGraphicsScene* myScene) {
        
    }

    QGraphicsLineItem* addLine(QPointF point_1, QPointF point_2);

    QGraphicsLineItem* addLine(QPointF point_1, QPointF point_2, QPen pen, QBrush brush);

    QGraphicsRectItem* addRect(QPointF point_1, QPointF point_2, QPen pen, QBrush brush);

    QGraphicsEllipseItem* addEllipse(QPointF point_1, QPointF point_2, QPen pen, QBrush brush);

    QGraphicsTextItem* addText(QPointF point_1, QFont font, QString text);

    QGraphicsPolygonItem* addTriangle(QVector<QPointF> points, QPen pen, QBrush brush);

    QGraphicsItemGroup* addGroup();

    QGraphicsLineItem* addLine(QGraphicsLineItem* lineCopy);

    QGraphicsRectItem* addRect(QGraphicsRectItem* rectCopy);

    QGraphicsEllipseItem* addEllipse( QGraphicsEllipseItem* ellipseCopy);

    QGraphicsTextItem* addText( QGraphicsTextItem* textCopy);

    QGraphicsPolygonItem* addTriangle( QGraphicsPolygonItem* triangleCopy);

    QGraphicsItemGroup* addGroup( QGraphicsItemGroup* groupCopy);


    void setSelected(bool value);

    bool deleteGraphics();
};

