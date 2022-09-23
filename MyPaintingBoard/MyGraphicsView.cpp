#include "MyGraphicsView.h"
#include <QMouseEvent>
#include <qmouseeventtransition.h>


MyGraphicsView::MyGraphicsView(QWidget* parent)
{

}

void MyGraphicsView::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QPoint point = event->pos();
		emit mouseClicked(point);
	}
	QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event) {
	QPoint point = event->pos();
	emit mouseMovePoint(point);
	QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QPoint point = event->pos();
		emit mouseReleased(point);
	}
	QGraphicsView::mouseReleaseEvent(event);
}

void MyGraphicsView::mouseDoubleClickEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QPoint point = event->pos();
		emit mouseDoubleClicked(point);
	}
	QGraphicsView::mouseDoubleClickEvent(event);
}
