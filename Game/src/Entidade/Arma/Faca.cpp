#include "pch.h"
#include "Entidade/Arma/Faca.h"

namespace Armas {
	const int Faca::damage = 2;// dano que causa

	const unsigned int Faca::id = 92;

	Faca::Faca(sf::Vector2f pos) :
		attacker(false),
		pColidiu(nullptr)
	{
		textura.loadFromFile(string(IMG) + "Faca.png");
		body.setTexture(&textura);
		body.setPosition(pos);
		body.setSize(sf::Vector2f(10.f, 3.f));
		hit.loadFromFile(string(SFX) + "knife-stab.wav");
		sfx.setBuffer(hit);
	}

	Faca::~Faca()
	{
	}

	bool Faca::getAttacker() const
	{
		return attacker;
	}

	void Faca::setAttacker()
	{
		attacker = true;
	}

	int Faca::getDamage() const
	{
		return damage;
	}

	unsigned int Faca::getId() const
	{
		return id;
	}

	void Faca::attack()
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