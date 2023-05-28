#pragma once
#include "../../EntidadeMovel.h"
#include "EnemyRanged.h"

class Projectile : public Entidades::EntidadeMovel
{
private:
	EnemyRanged* caster;
	int damage;
public:
	Projectile(sf::Vector2f pos, int id);
	~Projectile();

	void setCaster(EnemyRanged* pCaster) { caster = pCaster; }
	EnemyRanged* getCaster() { return caster; }

	void move() {}
	void attack() {}
};

