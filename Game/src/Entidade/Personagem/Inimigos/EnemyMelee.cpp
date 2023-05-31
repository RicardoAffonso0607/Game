#include "pch.h"
#include "Entidade/Personagem/Inimigos/EnemyMelee.h"

EnemyMelee::EnemyMelee(sf::Vector2f pos, int id) : Enemies(pos, id)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = true;

	this->life = 20;

	body.setFillColor(sf::Color::Red);
	body.setPosition(pos);
}

EnemyMelee::~EnemyMelee()
{
}

void EnemyMelee::move()
{
	if (pPlayer)
	{
		//body.move((float)pos.x - pPlayer->getPos().x, (float)pos.y - pPlayer->getPos().y);
	}
}

void EnemyMelee::attack()
{
}
