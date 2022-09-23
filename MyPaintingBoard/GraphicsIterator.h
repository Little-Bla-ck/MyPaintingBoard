#pragma once
#include <vector>
#include "Graphics.h"

class GraphicsIterator
{
private:
	std::vector<Graphics*> graphicsIterator;

	static GraphicsIterator* instance;

	GraphicsIterator() {};
	~GraphicsIterator() {};

private:
	class Deletor {
	public:
		~Deletor() {
			if (GraphicsIterator::instance != NULL) {
				delete GraphicsIterator::instance;
			}
		}
	};
	static Deletor deletor;

public:
	static GraphicsIterator* getInstance() {
		if (instance == NULL) {
			instance = new GraphicsIterator();
		}
		return instance;
	}

	void addGraphics(Graphics* graphics);

	void setSelected(bool value);

	Graphics* findGraphics(QGraphicsItem* item);
};



