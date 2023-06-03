#include "pch.h"
#include "Entidade/Personagem/Jogador/Ninja.h"

namespace Jogadores {
	Ninja::Ninja(sf::Vector2f pos, float pl_life) :
		id(1),
		size(sf::Vector2f(110.f, 180.f)),
		vel(sf::Vector2f(10.f, 13.f)),
		life(pl_life),
		mass(.9f)
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Ninja::~Ninja()
	{
	}
}