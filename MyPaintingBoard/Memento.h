#pragma once
#include "MyGraphicsScene.h"
#include "Graphics.h"
class Memento
{
public:
	Memento(MyGraphicsScene* scene) {
		this->scene = scene;
	}

	void setState(MyGraphicsScene* scene) {
		this->scene = scene;
	}

	MyGraphicsScene* getState() {
		return this->scene;
	}

private:
	MyGraphicsScene* scene;
};

