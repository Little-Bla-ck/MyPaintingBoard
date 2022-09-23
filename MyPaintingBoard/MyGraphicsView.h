#ifndef MYGRAPHICSVIEW_H

#pragma once

#include <qgraphicsview.h>
#include <qobject.h>
#include <QGraphicsView>

class MyGraphicsView :
    public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget * parent = nullptr);


signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
    void mouseReleased(QPoint point);
    void mouseDoubleClicked(QPoint point);

protected:
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

public slots:
};
#endif

