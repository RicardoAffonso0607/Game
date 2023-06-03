#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Medjai::Medjai(sf::Vector2f pos, int id) :
			life(20),
			size(sf::Vector2f(80.f, 150.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Medjai::~Medjai()
		{
		}
	}
}