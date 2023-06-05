#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	const int Flecha::damage = 10;

	const unsigned int Flecha::id = 83;

	Flecha::Flecha(sf::Vector2f pos)
	{
		body.setSize(sf::Vector2f(40.f, 15.f));
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{
	}

	float Flecha::getMass() const
	{
		return mass;
	}
	
	int Flecha::getDamage() const
	{
		return damage;
	}

	unsigned int Flecha::getId() const
	{
		return id;
	}

	void Flecha::attack()
	{
		if (colidiu)
		{
			if (pColidiu->getDamageable())
				pColidiu->applyDamage(damage);
			delete this;
		}
	}
}
