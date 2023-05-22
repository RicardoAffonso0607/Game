#pragma once

#include "Obstacles.h"

class ObstacleSlowness : public Obstacles
{
private:
	int slowness;

public:
	ObstacleSlowness(sf::Vector2f pos, int id);
	~ObstacleSlowness();
};

