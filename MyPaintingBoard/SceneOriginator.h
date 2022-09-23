#pragma once
#include <string.h>
#include <string>
#include "Memento.h"
using namespace std;
class SceneOriginator
{
public:
	Memento* getMemento();

	Memento* createMemeto(MyGraphicsScene* scene);

	Memento* restoreMemento();

private:
	std::vector<Memento*> mementos;
	// ×î¶à´æ50²½

	int index = 0;
};

