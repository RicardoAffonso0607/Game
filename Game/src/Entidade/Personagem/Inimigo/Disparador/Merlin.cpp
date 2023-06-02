#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"

namespace Inimigos {
	namespace Disparadores {
		Merlin::Merlin(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Merlin::~Merlin()
		{

		}
	}
}