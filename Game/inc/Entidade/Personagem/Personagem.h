#pragma once

#include "../Entidade.h"

class Personagem : public Entidade
{
protected:
	int damage;
	int life;
	int vel_x;
	int vel_y;
	int vel_max_x;
	int vel_max_y;

public:
	Personagem(sf::Vector2f pos, int id);
	~Personagem();

	virtual void move() = 0;
	virtual void attack() = 0;
};

