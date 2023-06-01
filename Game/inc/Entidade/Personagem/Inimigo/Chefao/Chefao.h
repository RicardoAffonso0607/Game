#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

class Chefao : public Inimigo
{
private:

public:
	Chefao(sf::Vector2f pos, int id);
	~Chefao();

	void move();
	void attack();
};