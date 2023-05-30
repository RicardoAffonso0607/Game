#include "pch.h"
#include "Entidade/Personagem/Inimigos/Projectile.h"

Projectile::Projectile(sf::Vector2f pos, int id) : Entidade(id), damage(20)
{
	this->movable = true;
	this->attacker = true;
	this->retarder = false;
	this->damageable = false;
	this->projected = true;

	this->pos = pos;
	caster = NULL;
}

Projectile::~Projectile()
{
	caster = NULL;
}

void Projectile::move()
{
}

void Projectile::attack()
{
}