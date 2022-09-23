#pragma once
#include "Graphics.h"
class EllipseItem : public Graphics
{
public:
	EllipseItem(QGraphicsEllipseItem* item) {
		this->item = item;
	}
};

