#pragma once
#include "GraphicsIterator.h"
class GraphicsAggregate
{
private:
	GraphicsIterator* iterator;
public:
	void addItem(Graphics* graphics);
	void setSeleted(bool value);
	Graphics* findGraphics(QGraphicsItem* item);
};

