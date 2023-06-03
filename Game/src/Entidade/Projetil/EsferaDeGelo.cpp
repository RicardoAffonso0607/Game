#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos, int id) :
		damage(7),
		size(sf::Vector2f(20.f, 20.f))
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	EsferaDeGelo::~EsferaDeGelo()
	{
	}
}
