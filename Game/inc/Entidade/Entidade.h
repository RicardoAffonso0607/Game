#pragma once

#include "Ente.h"

class Entidade : public Ente
{
protected:
	int x;
	int y; 
	sf::RectangleShape body;
	sf::RenderWindow* pWindow;

public:
	Entidade();
	~Entidade();

	void setWindow(sf::RenderWindow* window) { pWindow = window; }
	sf::RenderWindow* getWindow() { return pWindow; }

	void draw() {pWindow->draw(body); }
};

