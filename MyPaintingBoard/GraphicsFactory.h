#pragma once
#include "AbstractGraphicsFactory.h"
#include "qpoint.h"

class GraphicsFactory :
    public AbstractGraphicsFactory
{
public:
    LineItem* createLine(QGraphicsLineItem* lineItem) override;
    RectangleItem* createRect(QGraphicsRectItem* rectItem) override;
    EllipseItem* createEllipse(QGraphicsEllipseItem* ellipseItem) override;
    TextItem* createText(QGraphicsTextItem* textItem) override;
    TriangleItem* createTriangle(QGraphicsPolygonItem* triItem) override;
    GraphicsGroup* createGroup(QGraphicsItemGroup* itemGroup, QList<QGraphicsItem*> list) override;
};

