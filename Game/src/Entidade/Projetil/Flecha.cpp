#include "pch.h"
#include "Entidade/Projetil/Flecha.h"

namespace Projeteis {
	Flecha::Flecha(sf::Vector2f pos, int id) :
		damage(10)
	{
		body.setPosition(pos);
	}

	Flecha::~Flecha()
	{

	}
}