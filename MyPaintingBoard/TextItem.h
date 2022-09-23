#pragma once
#include "Graphics.h"
class TextItem : public Graphics
{
public:
	TextItem(QGraphicsTextItem* textItem) {
		this->item = textItem;
	}
};


