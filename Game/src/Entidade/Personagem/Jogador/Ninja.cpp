#include "pch.h"
#include "Entidade/Personagem/Jogador/Ninja.h"

namespace Jogadores {
	const unsigned int Ninja::id = 1;

	const float Ninja::mass = .9f;

	const sf::Vector2f Ninja::vel_max = sf::Vector2f(12.f, 15.f);

	Ninja::Ninja(sf::Vector2f pos, int pl_life) :
		life(pl_life),
		vel(vel_max)
	{
		body.setSize(sf::Vector2f(110.f, 180.f));
		body.setPosition(pos);
	}

	Ninja::~Ninja()
	{
	}

	sf::Vector2f Ninja::getVel() const
	{
		return vel;
	}

	unsigned int Ninja::getId() const
	{
		return id;
	}

	float Ninja::getMass() const
	{
		return mass;
	}
}