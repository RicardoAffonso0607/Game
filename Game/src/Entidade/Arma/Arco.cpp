#include "pch.h"
#include "Entidade/Arma/Arco.h"

namespace Armas {
	Arco::Arco() :
		damage(1),
		delay(sf::milliseconds(400))
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

	sf::Time Arco::getDelay() const
	{
		return delay;
	}
}