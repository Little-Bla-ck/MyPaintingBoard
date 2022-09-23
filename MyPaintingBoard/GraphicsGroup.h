#pragma once
#include "Graphics.h"
using namespace std;
class GraphicsGroup :
    public Graphics
{
public:
    GraphicsGroup(QGraphicsItemGroup* group, QList<QGraphicsItem*> list) {
        this->item = group;

        for (auto item : list) {
            ++size;
            groupList.push_back(item);
        }
    }

    int getSize() {
        return size;
    }

    QGraphicsItem* getGroupItem(int index) {
        return groupList[index];
    }

private:
    QGraphicsItemGroup group;

    vector<QGraphicsItem*> groupList;

    int size = 0;
};

