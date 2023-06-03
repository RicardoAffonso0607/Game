#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos, int id) :
		damage(7),
		id(82),
		pCaster(nullptr)
	{
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
	}

	EsferaDeGelo::~EsferaDeGelo()
	{
	}
	
	int EsferaDeGelo::getDamage()
	{
		return damage;
	}

	Inimigos::Disparador* EsferaDeGelo::getCaster()
	{
		return pCaster;
	}

	void EsferaDeGelo::setCaster(Inimigos::Disparador* caster)
	{
		pCaster = caster;
	}
}
