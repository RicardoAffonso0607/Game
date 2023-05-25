#pragma once
#include "../../Entidade.h"
#include "EnemyRanged.h"

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

	void move() {}
	void attack() {}
};

