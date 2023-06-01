#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

Retardante::Retardante(sf::Vector2f pos, int id) : Obstaculo(pos, id), slowness(3)
{
	this->movable = false;
	this->attacker = false;
	this->retarder = true;
	this->damageable = false;

}

Retardante::~Retardante()
{
}
