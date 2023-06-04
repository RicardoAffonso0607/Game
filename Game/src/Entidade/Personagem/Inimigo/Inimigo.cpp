#include "pch.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Inimigo::Inimigo()
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::setPlayer(Jogador* pPla)
{
	pPlayer = pPla;
}