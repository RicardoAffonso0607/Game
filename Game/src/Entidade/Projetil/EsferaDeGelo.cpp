#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos)
	{
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
	}

	EsferaDeGelo::~EsferaDeGelo()
	{
	}
	
	int EsferaDeGelo::getDamage() const
	{
		return damage;
	}

	Inimigos::Disparador* EsferaDeGelo::getEnemyCaster()
	{
		return pEnemyCaster;
	}

	void EsferaDeGelo::setEnemyCaster(Inimigos::Disparador* caster)
	{
		pEnemyCaster = caster;
	}
}
