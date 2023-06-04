#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"

namespace Inimigos {
	namespace Disparadores {
		Horus::Horus(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(100.f, 180.f));
			body.setPosition(pos);
		}

		Horus::~Horus()
		{
		}

		unsigned int Horus::getId() const
		{
			return id;
		}
	}
}