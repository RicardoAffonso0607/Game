#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Plataforma/Areal.h"

namespace Plataformas {
	Areal::Areal(sf::Vector2f pos, sf::Vector2f size) :
		id(41)
	{
		body.setSize(size);
		body.setPosition(pos);
	}

	Areal::~Areal()
	{
	}

	unsigned int Areal::getId() const
	{
		return id;
	}
}