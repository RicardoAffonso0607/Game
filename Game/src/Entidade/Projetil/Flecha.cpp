#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	const int Flecha::damage = 20;

	const unsigned int Flecha::id = 83;

	Flecha::Flecha(sf::Vector2f pos)
	{
		textura.loadFromFile(string(IMG) + "Flecha.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(70.f, 30.f));
		body.setPosition(pos);
		hit.loadFromFile(string(SFX) + "arrow-hit.wav");
		sfx.setBuffer(hit);
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
		if (pColidiu->getDamageable())
			pColidiu->applyDamage(damage);
	}
}
