#include "pch.h"
#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

Jogador* Inimigo::pPlayer(nullptr);

Inimigo::Inimigo(sf::Vector2f pos, int id) : Personagem(pos, id)
{
	pPlayer = nullptr;
	this->life = 0;
}

Inimigo::~Inimigo()
{
}

void Inimigo::setPlayer(Jogador* pPla)
{
	if(pPla)
		pPlayer = pPla;
}