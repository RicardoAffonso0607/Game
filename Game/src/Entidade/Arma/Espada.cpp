#include "pch.h"
#include "Entidade/Arma/Espada.h"

namespace Armas {
	Espada::Espada(sf::Vector2f pos, Personagem* pPer)
	{
		pPersonagem = pPer;
		body.setPosition(pos + sf::Vector2f(pPersonagem->getEntSize().x, .3f * pPersonagem->getEntSize().y));
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
