#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Spartacus::Spartacus(sf::Vector2f pos) :
			id(62),
			life(50),
			size(sf::Vector2f(80.f, 150.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Spartacus::~Spartacus()
		{
		}
	}
}