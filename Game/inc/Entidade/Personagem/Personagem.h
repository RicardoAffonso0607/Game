#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	int damage;
	int retard;
	int life;
	int vel_x;
	int vel_y;
	int vel_max_x;
	int vel_max_y;

public:
	Personagem(sf::Vector2f pos, int id);
	~Personagem();
	void subtractLife(int damaged) { life -= damaged; }
	void subtractVelocity(int retarded) { vel_x -= retarded; }
	int getRetarder() { return retard; }
	int getDamage() { return damage; }
};