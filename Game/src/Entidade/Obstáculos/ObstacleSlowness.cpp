#include "pch.h"
#include "../../../inc/Entidade/Obst�culos/ObstacleSlowness.h"

ObstacleSlowness::ObstacleSlowness(sf::Vector2f pos, int id) : Obstacles(pos, id), slowness(3)
{
}

ObstacleSlowness::~ObstacleSlowness()
{
}
