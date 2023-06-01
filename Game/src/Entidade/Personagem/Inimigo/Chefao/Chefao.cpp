#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

Chefao::Chefao(sf::Vector2f pos, int id) : Inimigo(pos,id)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = true;

	this->life = 100;
	this->damage = 10;

	body.setFillColor(sf::Color::White);
	body.setPosition(pos);
}

Chefao::~Chefao()
{
}

void Chefao::move()
{
}

void Chefao::attack()
{
}
