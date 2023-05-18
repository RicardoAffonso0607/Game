#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	int vida;
	int vel_x;
	int vel_y;
	int vel_max_x;
	int vel_max_y;

public:
	Personagem();
	~Personagem();

	virtual void move() = 0;
};

