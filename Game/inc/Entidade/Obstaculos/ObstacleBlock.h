#pragma once

#include "Entidade/Obstaculos/Obstacles.h"

class ObstacleBlock : public Obstacles
{
private:

public:
	ObstacleBlock(sf::Vector2f pos, int id);
	~ObstacleBlock();
};

