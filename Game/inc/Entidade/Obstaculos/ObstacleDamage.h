#pragma once

#include "Entidade/Obstaculos/Obstacles.h"

class ObstacleDamage : public Obstacles
{
private:
	int damage;

public:
	ObstacleDamage(sf::Vector2f pos, int id);
	~ObstacleDamage();
};

