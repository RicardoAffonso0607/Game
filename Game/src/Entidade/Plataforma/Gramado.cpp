#include "pch.h"
#include "Entidade/Plataforma/Gramado.h"

namespace Plataformas {
	Gramado::Gramado(sf::Vector2f pos, sf::Vector2f size, int id)
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Gramado::~Gramado()
	{
	}
}