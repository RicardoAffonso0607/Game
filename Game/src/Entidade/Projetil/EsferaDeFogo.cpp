#include "pch.h"
#include "Entidade/Projetil/EsferaDeFogo.h"

namespace Projeteis {
	EsferaDeFogo::EsferaDeFogo(sf::Vector2f pos, int id) :
		damage(4),
		size(sf::Vector2f(20.f, 20.f))
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	EsferaDeFogo::~EsferaDeFogo()
	{
	}
	
	int EsferaDeFogo::getDamage()
	{
		return damage;
	}
}
