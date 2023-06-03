#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos, int id) :
		damage(4),
		id(81),
		pCaster(nullptr)
	{
		body.setSize(sf::Vector2f(20.f, 20.f));
		body.setPosition(pos);
	}

	EsferaDeFogo::~EsferaDeFogo()
	{
	}
	
	int EsferaDeFogo::getDamage()
	{
		return damage;
	}

	Inimigos::Disparador* EsferaDeFogo::getCaster()
	{
		return pCaster;
	}

	void EsferaDeFogo::setCaster(Inimigos::Disparador* caster)
	{
		pCaster = caster;
	}
}
