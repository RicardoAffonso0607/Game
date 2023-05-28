#pragma once
#include "../Ente.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;

public:
	Entidade(int id);
	~Entidade();

	virtual void move() = 0;
	virtual void attack() = 0;
};

