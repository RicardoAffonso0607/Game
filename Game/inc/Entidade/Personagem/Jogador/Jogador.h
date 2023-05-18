#pragma once

#include "Entidade/Personagem/Personagem.h"

class Jogador : public Personagem
{
private:

public:
	Jogador();
	~Jogador();

	void move();
};

