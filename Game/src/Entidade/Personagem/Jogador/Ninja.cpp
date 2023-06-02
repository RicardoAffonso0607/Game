#include "pch.h"
#include "Entidade/Personagem/Jogador/Ninja.h"

namespace Jogadores {
	Ninja::Ninja(sf::Vector2f pos, int id, float life)
	{
		body.setPosition(pos);
	}

	Ninja::~Ninja()
	{

	}
}