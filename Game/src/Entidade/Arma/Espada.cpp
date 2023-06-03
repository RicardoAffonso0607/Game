#include "pch.h"
#include "Entidade/Arma/Espada.h"

namespace Armas {
	Espada::Espada() :
		damage(5),
		id(93),
		delay(sf::milliseconds(500))
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

	int Espada::getId() const
	{
		return id;
	}

	sf::Time Espada::getDelay() const
	{
		return delay;
	}
}
