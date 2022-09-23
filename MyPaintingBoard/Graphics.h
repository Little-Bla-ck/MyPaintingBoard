#pragma once
#include <qgraphicsitem.h>
#include <qpoint.h>
enum ValueGraphics
{
	Line,
	Triangle,
	Rectangle,
	Ellipse,
	Text,
	Free
};

class Graphics
{
protected:
	int id;
	ValueGraphics value;
	QColor lineColor;
	QColor areaColor;
	bool isVisable = true;
	// 可见性
	bool isUnderMouse;
	// 是否在鼠标下
	bool isSelected;
	// 是否被选中
	qreal rotation = 0;
	// 旋转角度
	qreal scale = 1;
	// 缩放大小
	QPoint pos;

	QGraphicsItem* item;

public:
	static int currentId;
	// 用于实现id自增

	Graphics() {
		id = currentId;
		++currentId;
	}

	virtual QGraphicsItem* getItem() {
		return item;
	}
};

