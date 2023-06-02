#include "pch.h"
#include "Entidade/Plataforma/Gramado.h"

namespace Plataformas {
	Gramado::Gramado(sf::Vector2f pos, int id)
	{
		body.setPosition(pos);
	}

	Gramado::~Gramado()
	{

	}
}