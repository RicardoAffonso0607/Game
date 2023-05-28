#pragma once
#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Inimigos/EnemyRanged.h"

class Projectile : public Entidade
{
private:
	EnemyRanged* caster;
	int damage;
public:
	Projectile(sf::Vector2f pos, int id);
	~Projectile();

	void setCaster(EnemyRanged* pCaster) { caster = pCaster; }
	EnemyRanged* getCaster() { return caster; }

	void move();
	void attack();
};

