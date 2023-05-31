#include "pch.h"
#include "Entidade/Obstaculos/ObstacleDamage.h"

ObstacleDamage::ObstacleDamage(sf::Vector2f pos, int id) : Obstacles(pos, id), damage(1)
{
	this->movable = false;
	this->attacker = true;
	this->retarder = false;
	this->damageable = false;


}

ObstacleDamage::~ObstacleDamage()
{
}
