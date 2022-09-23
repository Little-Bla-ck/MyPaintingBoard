#include "GraphicsIterator.h"
#include "Graphics.h"

GraphicsIterator* GraphicsIterator::instance = NULL;

int Graphics::currentId = 0;

void GraphicsIterator::addGraphics(Graphics* graphics)
{
	graphicsIterator.push_back(graphics);
}

void GraphicsIterator::setSelected(bool value)
{
	if (value) {
		for (int i = 0; i < graphicsIterator.size(); ++i) {
			if (graphicsIterator[i] != NULL) {
				if (graphicsIterator[i]->getItem() != NULL) {
					graphicsIterator[i]->getItem()->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
				}
			}
		}
	}
	else {
		for (int i = 0; i < graphicsIterator.size(); ++i) {
			if (graphicsIterator[i] != NULL) {
				if (graphicsIterator[i]->getItem() != NULL) {
					graphicsIterator[i]->getItem()->setFlags(QGraphicsItem::ItemIsFocusable);
				}
			}
		}
	}
	
}

Graphics* GraphicsIterator::findGraphics(QGraphicsItem* item)
{
	for (int i = 0; i < graphicsIterator.size(); ++i) {
		if (graphicsIterator[i]->getItem() == item) {
			return graphicsIterator[i];
		}
	}
}
