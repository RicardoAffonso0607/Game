#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:


public:
	Personagem(sf::Vector2f pos, int id);
	~Personagem();
};