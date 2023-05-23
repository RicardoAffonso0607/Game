#include "pch.h"
#include "Entidade/Personagem/Inimigos/EnemyRanged.h"
#include "Entidade/Personagem/Inimigos/Projectile.h"

EnemyRanged::EnemyRanged(sf::Vector2f pos, int id) : Enemies(pos,id)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = true;

	magic = NULL;
	this->life = 50;
	this->damage = 0;

	body.setFillColor(sf::Color::Red);
	body.setPosition(pos);
}

EnemyRanged::~EnemyRanged()
{
}

void EnemyRanged::move()
{
}

void EnemyRanged::atack()
{
	magic = new Projectile(sf::Vector2f(pos.x, pos.y), 10);
	magic->setCaster(this);
}
