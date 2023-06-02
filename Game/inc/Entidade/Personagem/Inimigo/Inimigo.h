#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

class Inimigo : public Personagem
{
protected:
	static Jogador* pPlayer;

public:
	Inimigo();
	virtual ~Inimigo();

	virtual void move() = 0;
	virtual void attack() = 0;

	static void setPlayer(Jogador* pPla);
	Jogador* getPlayer() { return pPlayer; }
};