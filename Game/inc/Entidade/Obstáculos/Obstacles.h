#pragma once

#include "../Entidade.h"

class Obstacles : public Entidade
{
protected:

public:
	Obstacles(sf::Vector2f pos, int id);
	~Obstacles();

	void move() = 0;
	void attack() = 0;
};

