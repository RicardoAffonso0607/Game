#include "pch.h"
#include "../../Game/inc/Entidade/Personagem/Inimigos/Projectile.h"

Projectile::Projectile(sf::Vector2f pos, int id) : EntidadeMovel(id, pos), damage(20)
{
	caster = NULL;
}

Projectile::~Projectile()
{
	caster = NULL;
}
