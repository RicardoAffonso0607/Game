#include "pch.h"
#include "../../Game/inc/Entidade/Personagem/Inimigos/Enemies.h"

Jogador* Enemies::pPlayer(NULL);

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

