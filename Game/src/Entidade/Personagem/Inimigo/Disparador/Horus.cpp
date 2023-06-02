#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Horus.h"

namespace Inimigos {
	namespace Disparadores {
		Horus::Horus(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Horus::~Horus()
		{

		}
	}
}