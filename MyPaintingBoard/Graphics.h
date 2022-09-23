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
	// �ɼ���
	bool isUnderMouse;
	// �Ƿ��������
	bool isSelected;
	// �Ƿ�ѡ��
	qreal rotation = 0;
	// ��ת�Ƕ�
	qreal scale = 1;
	// ���Ŵ�С
	QPoint pos;

	QGraphicsItem* item;

public:
	static int currentId;
	// ����ʵ��id����

	Graphics() {
		id = currentId;
		++currentId;
	}

	virtual QGraphicsItem* getItem() {
		return item;
	}
};

