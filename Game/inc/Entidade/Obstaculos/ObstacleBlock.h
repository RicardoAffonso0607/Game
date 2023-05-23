#pragma once

#include "Obstacles.h"

class ObstacleBlock : public Obstacles
{
private:

public:
	ObstacleBlock(sf::Vector2f pos, int id);
	~ObstacleBlock();
};

