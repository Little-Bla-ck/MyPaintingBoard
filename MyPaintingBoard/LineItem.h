#pragma once
#include "Graphics.h"
class LineItem : public Graphics
{
private:
public:
    LineItem(QGraphicsLineItem* item) {
        this->item = item;
    };
    
};

