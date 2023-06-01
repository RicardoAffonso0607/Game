#pragma once

#include "Entidade/Entidade.h"

class Plataforma : public Entidade
{
private:

public:
	Plataforma(sf::Vector2f pos, int id);
	~Plataforma();

	void move();
	void attack();
};