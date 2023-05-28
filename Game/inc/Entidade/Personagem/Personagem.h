#pragma once

#include "../EntidadeMovel.h"

class Personagem : public Entidades::EntidadeMovel
{
protected:
	int damage;
	int life;

public:
	Personagem(sf::Vector2f pos, int id);
	~Personagem();

	virtual void move() = 0;
	virtual void attack() = 0;
};

