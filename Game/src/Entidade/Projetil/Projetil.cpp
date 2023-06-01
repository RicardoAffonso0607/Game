#include "pch.h"
#include "Entidade/Projetil/Projetil.h"

Projetil::Projetil(sf::Vector2f pos, int id) : Entidade(id), damage(20)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = false;
	this->projected = true;

	this->pos = pos;
	caster = nullptr;
}

Projetil::~Projetil()
{
	caster = nullptr;
}

void Projetil::move()
{
}

void Projetil::attack()
{
}