#pragma once

#include "Entidade/Entidade.h"

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
	void subtractLife(int* damage) { life -= damage; }
	void subtractVelocity(int* retard) { vel_x -= retard; }
	void elapsedRetarder(){}
	void resetRetarder(){}
};

