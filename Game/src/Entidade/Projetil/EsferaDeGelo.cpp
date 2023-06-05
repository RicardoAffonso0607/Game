#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	const int EsferaDeGelo::damage = 7;

	const unsigned int EsferaDeGelo::id = 82;

	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos)
	{
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
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
		//if (colidiu)
		//{
		//	if (pColidiu->getDamageable())
		//		pColidiu->applyDamage(damage);
		//	delete this;
		//}
	}
}
