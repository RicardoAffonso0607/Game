#include "pch.h"
#include "Entidade/Arma/Espada.h"

namespace Armas {
	const int Espada::damage = 5;// dano que causa
	
	const unsigned int Espada::id = 93;

	Espada::Espada(sf::Vector2f pos) :
		attacker(false),
		pColidiu(nullptr)
	{
		body.setPosition(pos);
		body.setSize(sf::Vector2f(20.f, 3.f));
	}

	Espada::~Espada()
	{
	}

	bool Espada::getAttacker() const
	{
		return attacker;
	}

	void Espada::setAttacker()
	{
		attacker = true;
	}

	int Espada::getDamage() const
	{
		return damage;
	}

	unsigned int Espada::getId() const
	{
		return id;
	}

	void Espada::attack()
	{
		if (colidiu && attacker)
		{
			if (pColidiu->getDamageable()) {
				pColidiu->applyDamage(damage);
				attacker = false;
			}
		}
	}
}