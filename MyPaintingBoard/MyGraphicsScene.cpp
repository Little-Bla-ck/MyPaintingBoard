#include "MyGraphicsScene.h"

QGraphicsLineItem* MyGraphicsScene::addLine(QPointF point_1, QPointF point_2)
{
	auto temp = scene->addLine(point_1.x(), point_1.y(), point_2.x(), point_2.y());
	aggregate->addItem(factory->createLine(temp));
	scene->update();
	return temp;
}

QGraphicsLineItem* MyGraphicsScene::addLine(QPointF point_1, QPointF point_2, QPen pen, QBrush brush)
{
	auto temp = scene->addLine(point_1.x(), point_1.y(), point_2.x(), point_2.y(), pen);
	aggregate->addItem(factory->createLine(temp));
	scene->update();
	return temp;
}

QGraphicsRectItem* MyGraphicsScene::addRect(QPointF point_1, QPointF point_2, QPen pen, QBrush brush)
{
	auto temp = scene->addRect(point_1.x(), point_1.y(), point_2.x() - point_1.x(), point_2.y() - point_1.y(), pen, brush);
	aggregate->addItem(factory->createRect(temp));
	scene->update();
	return temp;
}

QGraphicsEllipseItem* MyGraphicsScene::addEllipse(QPointF point_1, QPointF point_2, QPen pen, QBrush brush)
{
	auto temp = scene->addEllipse(point_1.x(), point_1.y(), point_2.x() - point_1.x(), point_2.y() - point_1.y(), pen, brush);
	aggregate->addItem(factory->createEllipse(temp));
	scene->update();
	return temp;
}

QGraphicsTextItem* MyGraphicsScene::addText(QPointF point_1, QFont font, QString text)
{
	QGraphicsTextItem* textItem = scene->addText(text, font);
	textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
	textItem->setPos(point_1);
	aggregate->addItem(factory->createText(textItem));
	scene->update();
	return textItem;
}

QGraphicsPolygonItem* MyGraphicsScene::addTriangle(QVector<QPointF> points, QPen pen, QBrush brush)
{
	auto temp = scene->addPolygon(QPolygonF(points), pen, brush);
	aggregate->addItem(factory->createTriangle(temp));
	scene->update();
	return temp;
}

QGraphicsItemGroup* MyGraphicsScene::addGroup()
{
	auto group = scene->selectedItems();
	int num = group.size();

	if (num <= 1) {
		return nullptr;
	}

	QGraphicsItemGroup* itemGroup = new QGraphicsItemGroup();
	for (int i = 0; i < num; ++i) {
		group.at(i)->setSelected(false);
		itemGroup->addToGroup(group.at(i));
	}

	auto graphicsGroup = factory->createGroup(itemGroup, group);

	aggregate->addItem(graphicsGroup);

	scene->addItem(itemGroup);

	return itemGroup;
}

QGraphicsLineItem* MyGraphicsScene::addLine(QGraphicsLineItem* lineCopy)
{
	auto temp = scene->addLine(lineCopy->line(), lineCopy->pen());
	aggregate->addItem(factory->createLine(temp));
	scene->update();
	return temp;
}

QGraphicsRectItem* MyGraphicsScene::addRect(QGraphicsRectItem* rectCopy)
{
	auto temp = scene->addRect(rectCopy->rect(), rectCopy->pen(), rectCopy->brush());
	aggregate->addItem(factory->createRect(temp));
	scene->update();
	return temp;
}

QGraphicsEllipseItem* MyGraphicsScene::addEllipse(QGraphicsEllipseItem* ellipseCopy)
{
	auto temp = scene->addEllipse(ellipseCopy->rect(), ellipseCopy->pen(), ellipseCopy->brush());
	aggregate->addItem(factory->createEllipse(temp));
	scene->update();
	return temp;
}

QGraphicsTextItem* MyGraphicsScene::addText(QGraphicsTextItem* textCopy)
{
	QString test = textCopy->toPlainText();
	QGraphicsTextItem* textItem = scene->addText(test, textCopy->font());
	textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
	textItem->setPos(textCopy->pos());
	aggregate->addItem(factory->createText(textItem));
	scene->update();
	return textItem;
}

QGraphicsPolygonItem* MyGraphicsScene::addTriangle(QGraphicsPolygonItem* triangleCopy)
{
	auto temp = scene->addPolygon(triangleCopy->polygon(), triangleCopy->pen(), triangleCopy->brush());
	aggregate->addItem(factory->createTriangle(temp));
	scene->update();
	return temp;
}

QGraphicsItemGroup* MyGraphicsScene::addGroup(QGraphicsItemGroup* groupCopy)
{
	auto temp = aggregate->findGraphics(groupCopy);

	auto groupTemp = dynamic_cast<GraphicsGroup*>(temp);

	QList<QGraphicsItem*> listTemp;

	for (int i = 0; i < groupTemp->getSize(); ++i) {
		auto groupItemTemp = groupTemp->getGroupItem(i);
		switch (groupItemTemp->type()) {
		case QGraphicsRectItem::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsRectItem*>(groupItemTemp);
			listTemp.append(addRect(rectTemp));
			break;
		}
		case QGraphicsLineItem::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsLineItem*>(groupItemTemp);
			listTemp.append(addLine(rectTemp));
			break;
		}
		case QGraphicsEllipseItem::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsEllipseItem*>(groupItemTemp);
			listTemp.append(addEllipse(rectTemp));
			break;
		}
		case QGraphicsTextItem::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsTextItem*>(groupItemTemp);
			listTemp.append(addText(rectTemp));
			break;
		}
		case QGraphicsPolygonItem::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsPolygonItem*>(groupItemTemp);
			listTemp.append(addTriangle(rectTemp));
			break;
		}
		case QGraphicsItemGroup::Type: {
			auto rectTemp = qgraphicsitem_cast<QGraphicsItemGroup*>(groupItemTemp);
			listTemp.append(addGroup(rectTemp));
			break;
		}
		}
	}

	QGraphicsItemGroup* itemGroup = new QGraphicsItemGroup();

	for (int i = 0; i < groupTemp->getSize(); ++i) {
		itemGroup->addToGroup(listTemp.at(i));
	}

	auto graphicsGroup = factory->createGroup(itemGroup, listTemp);

	aggregate->addItem(graphicsGroup);

	scene->addItem(itemGroup);

	return itemGroup;
}



void MyGraphicsScene::setSelected(bool value)
{
	aggregate->setSeleted(value);
}


