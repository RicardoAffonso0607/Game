#pragma once

#include "../EntidadeFixa.h"

class Obstacles : public Entidades::EntidadeFixa
{
protected:

public:
	Obstacles(sf::Vector2f pos, int id);
	~Obstacles();

	void move() = 0;
	void attack() = 0;
};

