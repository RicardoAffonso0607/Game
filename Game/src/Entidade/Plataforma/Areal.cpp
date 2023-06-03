#include "pch.h"
#include "Entidade/Plataforma/Areal.h"

namespace Plataformas {
	Areal::Areal(sf::Vector2f pos, sf::Vector2f size, int id)
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Areal::~Areal()
	{

	}
}