#pragma once

#include "Entidade/Personagem/Inimigos/Enemies.h"

class EnemyMelee : public Enemies
{
private:
	
public:
	EnemyMelee(sf::Vector2f pos, int id);
	~EnemyMelee();

	void move();
	void attack();
};
