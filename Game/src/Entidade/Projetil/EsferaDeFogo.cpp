#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	const int EsferaDeFogo::damage = 4;

	const unsigned int EsferaDeFogo::id = 81;

	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos)
	{
		textura.loadFromFile(string(IMG) + "BolaDeFogo.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(80.f, 40.f));
		body.setPosition(pos);
		hit.loadFromFile(string(SFX) + "fire-hit.wav");
		sfx.setBuffer(hit);
	}

	EsferaDeFogo::~EsferaDeFogo()
	{
	}

	float EsferaDeFogo::getMass() const
	{
		return mass;
	}
	
	int EsferaDeFogo::getDamage() const
	{
		return damage;
	}

	unsigned int EsferaDeFogo::getId() const
	{
		return id;
	}

	void EsferaDeFogo::attack()
	{
		if (pColidiu->getDamageable() && pColidiu->getId() >= 1 && pColidiu->getId() <= 9)
			pColidiu->applyDamage(damage);
	}
}
