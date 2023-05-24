#pragma once
#include "Ente.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape body;
	sf::RenderWindow* pWindow;
	bool movable;
	bool attacker;
	bool retarder;
	bool damageable;
public:
	Entidade(int id);
	~Entidade();
	
	void setWindow(sf::RenderWindow* window) { pWindow = window; }
	sf::RenderWindow* getWindow() { return pWindow; }

	void draw() {pWindow->draw(body); }

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getEntSize() { return body.getSize(); }
	void changePosition(sf::Vector2f dif_pos) { body.move(dif_pos); }
	bool isMovable() { return movable; }
	bool isAttacker() { return attacker; }
	bool isRetarder() { return retarder; }
	bool isDamageable() { return damageable; }
};

