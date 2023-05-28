#pragma once

#include "Entidade/Entidade.h"

class Obstacles : public Entidade
{
protected:

public:
	Obstacles(sf::Vector2f pos, int id);
	~Obstacles();

<<<<<<< HEAD:Game/inc/Entidade/Obstaculos/Obstacles.h
	void move();
	void attack();
=======
	void move() = 0;
	void attack() = 0;
>>>>>>> main:Game/inc/Entidade/Obstáculos/Obstacles.h
};

