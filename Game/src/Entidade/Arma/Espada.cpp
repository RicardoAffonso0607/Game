#include "pch.h"
#include "Entidade/Arma/Espada.h"

namespace Armas {
	Espada::Espada()
	{
		body.setSize(sf::Vector2f(20.f, 3.f));
	}

	Espada::~Espada()
	{
	}

	int Espada::getDamage() const
	{
		return damage;
	}

	unsigned int Espada::getId() const
	{
		return id;
	}

	sf::Time Espada::getDelay() const
	{
		return delay;
	}
}
