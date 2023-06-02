#include "pch.h"
#include "Entidade/Projetil/EsferaDeGelo.h"

namespace Projeteis {
	EsferaDeGelo::EsferaDeGelo(sf::Vector2f pos, int id) :
		damage(7)
	{
		body.setPosition(pos);
	}

	EsferaDeGelo::~EsferaDeGelo()
	{

	}
}