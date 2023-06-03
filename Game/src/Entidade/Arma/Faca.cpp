#include "pch.h"
#include "Entidade/Arma/Faca.h"

namespace Armas {
	Faca::Faca() :
		damage(2),
		id(92),
		delay(sf::milliseconds(400))
	{
		body.setSize(sf::Vector2f(10.f, 3.f));
	}

	Faca::~Faca()
	{
	}

	int Faca::getDamage() const
	{
		return damage;
	}

	unsigned int Faca::getId() const
	{
		return id;
	}

	sf::Time Faca::getDelay() const
	{
		return delay;
	}
}