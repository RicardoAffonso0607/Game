#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

class CorpoACorpo : public Inimigo
{
private:
	
public:
	CorpoACorpo(sf::Vector2f pos, int id);
	~CorpoACorpo();

	void move();
	void attack();
};