#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	const int EsferaDeGelo::damage = 7;

	const unsigned int EsferaDeGelo::id = 82;

	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos)
	{
		textura.loadFromFile(string(IMG) + "BolaDeGelo.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(80.f, 40.f));
		body.setPosition(pos);
		hit.loadFromFile(string(SFX) + "ice-hit.wav");
		sfx.setBuffer(hit);
	}

	EsferaDeGelo::~EsferaDeGelo()
	{
	}

	float EsferaDeGelo::getMass() const
	{
		return mass;
	}
	
	int EsferaDeGelo::getDamage() const
	{
		return damage;
	}

	unsigned int EsferaDeGelo::getId() const
	{
		return id;
	}

	void EsferaDeGelo::attack()
	{
		if (pColidiu->getDamageable() && pColidiu->getId()>=1 && pColidiu->getId() <= 9)
			pColidiu->applyDamage(damage);
	}
}