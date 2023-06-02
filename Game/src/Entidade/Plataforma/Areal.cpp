#include "pch.h"
#include "Entidade/Plataforma/Areal.h"

namespace Plataformas {
	Areal::Areal(sf::Vector2f pos, int id)
	{
		body.setPosition(pos);
	}

	Areal::~Areal()
	{

	}
}