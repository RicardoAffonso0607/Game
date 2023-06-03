#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	Flecha::Flecha(sf::Vector2f pos, int id) :
		damage(10),
		size(sf::Vector2f(30.f, 10.f))
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{
	}
}
