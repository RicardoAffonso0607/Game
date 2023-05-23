#include "pch.h"
#include "../../Game/inc/Entidade/Personagem/Inimigos/Boss.h"

Boss::Boss(sf::Vector2f pos, int id) : Enemies(pos,id)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = true;

	this->life = 100;
	this->damage = 10;

	body.setFillColor(sf::Color::Red);
	body.setPosition(pos);
}

Boss::~Boss()
{
}

void Boss::move()
{
}

void Boss::atack()
{
}
