#pragma once

#include "Entidade/Entidade.h"

class Obstacles : public Entidade
{
protected:

public:
	Obstacles(sf::Vector2f pos, int id);
	~Obstacles();

	void move();
	void attack();
};

