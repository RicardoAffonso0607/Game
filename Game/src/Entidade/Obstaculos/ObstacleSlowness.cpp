#include "pch.h"
#include "../../../inc/Entidade/Obstaculos/ObstacleSlowness.h"

ObstacleSlowness::ObstacleSlowness(sf::Vector2f pos, int id) : Obstacles(pos, id), slowness(3)
{
	this->movable = false;
	this->attacker = false;
	this->retarder = true;
	this->damageable = false;

}

ObstacleSlowness::~ObstacleSlowness()
{
}
