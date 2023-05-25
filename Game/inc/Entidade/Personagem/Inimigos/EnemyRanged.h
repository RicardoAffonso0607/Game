#pragma once

#include "Enemies.h"
class Projectile;

class EnemyRanged : public Enemies
{
private:
	Projectile* magic;
public:
	EnemyRanged(sf::Vector2f pos, int id);
	~EnemyRanged();

	void move();
	void attack();
};

