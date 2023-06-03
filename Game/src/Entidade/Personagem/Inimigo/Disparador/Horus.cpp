#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"

namespace Inimigos {
	namespace Disparadores {
		Horus::Horus(sf::Vector2f pos, int id) :
			life(100),
			size(sf::Vector2f(100.f, 180.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Horus::~Horus()
		{
		}
	}
}