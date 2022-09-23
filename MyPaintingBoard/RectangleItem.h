#pragma once
#include "Graphics.h"
class RectangleItem : public Graphics
{
public:
	RectangleItem(QGraphicsRectItem* rectItem) {
		item = rectItem;
	}
};

