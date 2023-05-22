#pragma once
#include "../Ente.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape body;
	sf::RenderWindow* pWindow;

public:
	Entidade(int id);
	~Entidade();

	void setWindow(sf::RenderWindow* window) { pWindow = window; }
	sf::RenderWindow* getWindow() { return pWindow; }

	void draw() {pWindow->draw(body); }
};

