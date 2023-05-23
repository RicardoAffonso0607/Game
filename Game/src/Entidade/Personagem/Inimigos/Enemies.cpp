#include "pch.h"
#include "Entidade/Personagem/Inimigos/Enemies.h"

Enemies::Enemies(sf::Vector2f pos, int id) : Personagem(pos, id)
{
	pPlayer = NULL;
	this->life = 0;
}

Enemies::~Enemies()
{
}

void Enemies::setPlayer(Jogador* pPla)
{
	if(pPla)
		pPlayer = pPla;
}

