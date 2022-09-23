#include "GraphicsAggregate.h"
#include "GraphicsIterator.h"

void GraphicsAggregate::addItem(Graphics* graphics)
{
	GraphicsIterator::getInstance()->addGraphics(graphics);
}

void GraphicsAggregate::setSeleted(bool value)
{
	GraphicsIterator::getInstance()->setSelected(value);
}

Graphics* GraphicsAggregate::findGraphics(QGraphicsItem* item)
{
	return GraphicsIterator::getInstance()->findGraphics(item);
}
