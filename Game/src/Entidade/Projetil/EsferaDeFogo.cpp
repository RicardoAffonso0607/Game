#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	const int EsferaDeFogo::damage = 4;

	const unsigned int EsferaDeFogo::id = 81;

	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos)
	{
		textura.loadFromFile(string(IMG) + "BolaDeFogo.png");
		body.setTexture(&textura);
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
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
		//if (colidiu)
		//{
		//	if (pColidiu->getDamageable())
		//		pColidiu->applyDamage(damage);
		//	delete this;
		//}
	}
}
