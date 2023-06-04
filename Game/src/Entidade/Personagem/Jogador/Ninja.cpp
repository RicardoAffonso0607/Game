#include "pch.h"
#include "Entidade/Personagem/Jogador/Ninja.h"

namespace Jogadores {
	const unsigned int Ninja::id = 1;

	const float Ninja::mass = .9f;

	Ninja::Ninja(sf::Vector2f pos, int pl_life) :
		life(pl_life)
	{
		body.setSize(sf::Vector2f(110.f, 180.f));
		body.setPosition(pos);
	}

	Ninja::~Ninja()
	{
	}

	unsigned int Ninja::getId() const
	{
		return id;
	}
}