#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

class Lutadora : public Jogador
{
private:

public:
	Lutadora(sf::Vector2f pos, int id, float life);
	~Lutadora();
};

