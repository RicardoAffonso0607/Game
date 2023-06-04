#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"

namespace Inimigos {
	namespace Disparadores {
		Merlin::Merlin(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(100.f, 180.f));
			body.setPosition(pos);
		}

		Merlin::~Merlin()
		{
		}

		unsigned int Merlin::getId() const
		{
			return id;
		}
	}
}