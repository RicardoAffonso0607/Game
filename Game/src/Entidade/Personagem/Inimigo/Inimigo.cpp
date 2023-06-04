#include "pch.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

const bool Inimigo::attacker = true;

Inimigo::Inimigo() :
	pPlayer(nullptr)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::setPlayer(Jogador* pPla)
{
	pPlayer = pPla;
}

bool Inimigo::getAttacker() const
{
	return attacker;
}