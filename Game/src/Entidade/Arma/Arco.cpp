#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	Arco::Arco()
	{
		body.setSize(sf::Vector2f(8.f, 20.f));
	}

	Arco::~Arco()
	{
	}

	int Arco::getDamage() const
	{
		return damage;
	}

	unsigned int Arco::getId() const
	{
		return id;
	}

	sf::Time Arco::getDelay() const
	{
		return sf::Time::Zero;//delay;
	}
}