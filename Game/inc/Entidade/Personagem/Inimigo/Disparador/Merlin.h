#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

class Merlin : public Disparador
{
private:

public:
	Merlin(sf::Vector2f pos, int id);
	~Merlin();
};