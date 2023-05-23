#include "pch.h"
#include "../../../inc/Entidade/Obstaculos/Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, int id) : Obstacles(pos, id)
{
	this->movable = false;
	this->attacker = false;
	this->retarder = false;
	this->damageable = false;

}

Plataforma::~Plataforma()
{
}
