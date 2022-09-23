#pragma once
#include "Graphics.h"
class TriangleItem : public Graphics
{
public:
    TriangleItem(QGraphicsPolygonItem* triItem) {
        this->item = triItem;
    }
};

