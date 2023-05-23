#include "pch.h"
#include "../../../inc/Entidade/Obstaculos/ObstacleBlock.h"

ObstacleBlock::ObstacleBlock(sf::Vector2f pos, int id) : Obstacles(pos, id)
{
	this->movable = false;
	this->attacker = false;
	this->retarder = false;
	this->damageable = false;


}

ObstacleBlock::~ObstacleBlock()
{
}
