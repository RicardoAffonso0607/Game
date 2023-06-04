#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos)
	{
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
	}

	EsferaDeFogo::~EsferaDeFogo()
	{
	}
	
	int EsferaDeFogo::getDamage() const
	{
		return damage;
	}

	Inimigos::Disparador* EsferaDeFogo::getEnemyCaster()
	{
		return pEnemyCaster;
	}

	void EsferaDeFogo::setEnemyCaster(Inimigos::Disparador* caster)
	{
		pEnemyCaster = caster;
	}
}
