#include "pch.h"
#include "../../Game/inc/Entidade/Personagem/Inimigos/Projectile.h"

Projectile::Projectile(sf::Vector2f pos, int id) : Entidade(id), damage(20)
{
	this->pos = pos;
	caster = NULL;
}

Projectile::~Projectile()
{
	caster = NULL;
}
