#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	float damage;
	float retard;
	float life;
	float vel_x;
	float vel_y;
	float vel_max_x;
	float vel_max_y;

public:
	Personagem(sf::Vector2f pos, int id);
	~Personagem();
	void subtractLife(float damaged) { life -= damaged; }
	void subtractVelocity(float retarded) { vel_x -= retarded; }
	float getRetarder() { return retard; }
	float getDamage() { return damage; }
	virtual void move() = 0;
	virtual void attack() = 0;
};

