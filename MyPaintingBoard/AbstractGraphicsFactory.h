#pragma once
#include "Graphics.h"
#include "LineItem.h"
#include "EllipseItem.h"
#include "RectangleItem.h"
#include "TriangleItem.h"
#include "TextItem.h"
#include "LineItem.h"
#include "GraphicsGroup.h"


class AbstractGraphicsFactory
{
public:
	virtual LineItem* createLine(QGraphicsLineItem* lineItem) = 0;
	virtual RectangleItem* createRect(QGraphicsRectItem* rectItem) = 0;
	virtual EllipseItem* createEllipse(QGraphicsEllipseItem* ellipseItem) = 0;
	virtual TextItem* createText(QGraphicsTextItem* textItem) = 0;
	virtual TriangleItem* createTriangle(QGraphicsPolygonItem* triItem) = 0;
	virtual GraphicsGroup* createGroup(QGraphicsItemGroup* itemGroup, QList<QGraphicsItem*> list) = 0;
};

