#include "pch.h"
#include "Entidade/Personagem/Inimigo/Disparador/Merlin.h"

namespace Inimigos {
	namespace Disparadores {
		Merlin::Merlin(sf::Vector2f pos, int id) :
			life(80),
			size(sf::Vector2f(100.f,180.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Merlin::~Merlin()
		{
		}
	}
}