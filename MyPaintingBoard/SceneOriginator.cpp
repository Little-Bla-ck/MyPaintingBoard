#include "SceneOriginator.h"

Memento* SceneOriginator::getMemento()
{
	return this->mementos[index];
}

Memento* SceneOriginator::createMemeto(MyGraphicsScene* scene)
{
	auto memento = new Memento(scene);

	++index;

	if (index == mementos.size()) {
		mementos.push_back(memento);
	}
	else {
		mementos[index] = memento;
	}
	return memento;
}

Memento* SceneOriginator::restoreMemento()
{
	if (index == 0) {
		return nullptr;
	}
	else {
		return mementos[--index];
	}
}
