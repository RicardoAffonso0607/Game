#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

Inerte::Inerte(sf::Vector2f pos, int id) : Obstaculo(pos, id)
{
	this->movable = false;
	this->attacker = false;
	this->retarder = false;
	this->damageable = false;

	body.setFillColor(sf::Color::Green);
	body.setPosition(pos);
}

Inerte::~Inerte()
{
}
