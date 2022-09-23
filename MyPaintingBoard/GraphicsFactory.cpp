#include "GraphicsFactory.h"

LineItem* GraphicsFactory::createLine(QGraphicsLineItem* lineItem)
{
	return new LineItem(lineItem);
}

RectangleItem* GraphicsFactory::createRect(QGraphicsRectItem* rectItem)
{
	return new RectangleItem(rectItem);
}

EllipseItem* GraphicsFactory::createEllipse(QGraphicsEllipseItem* ellipseItem)
{
	return new EllipseItem(ellipseItem);
}

TextItem* GraphicsFactory::createText(QGraphicsTextItem* textItem)
{
	return new TextItem(textItem);
}

TriangleItem* GraphicsFactory::createTriangle(QGraphicsPolygonItem* triItem)
{
	return new TriangleItem(triItem);
}

GraphicsGroup* GraphicsFactory::createGroup(QGraphicsItemGroup* itemGroup, QList<QGraphicsItem*> list)
{
	return new GraphicsGroup(itemGroup, list);
}




