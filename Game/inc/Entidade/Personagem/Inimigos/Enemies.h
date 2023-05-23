#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

class Enemies : public Personagem
{
protected:
	Jogador* pPlayer;
public:
	Enemies(sf::Vector2f pos, int id);
	~Enemies();

	virtual void move() = 0;
	virtual void atack() = 0;

	void setPlayer(Jogador* pPla);
	Jogador* getPlayer() { return pPlayer; }
};

