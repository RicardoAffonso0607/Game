#pragma once

#include "Enemies.h"

class Boss : public Enemies
{
private:

public:
	Boss(sf::Vector2f pos, int id);
	~Boss();

	void move();
	void atack();
};

