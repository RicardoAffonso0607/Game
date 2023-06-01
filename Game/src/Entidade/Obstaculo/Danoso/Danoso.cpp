#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

Danoso::Danoso(sf::Vector2f pos, int id) : Obstaculo(pos, id), damage(1)
{
	this->movable = false;
	this->attacker = true;
	this->retarder = false;
	this->damageable = false;


}

Danoso::~Danoso()
{
}
