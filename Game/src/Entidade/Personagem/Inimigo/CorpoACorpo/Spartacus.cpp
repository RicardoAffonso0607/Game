#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Spartacus::Spartacus(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(80.f, 150.f));
			body.setPosition(pos);
		}

		Spartacus::~Spartacus()
		{
		}

		unsigned int Spartacus::getId() const
		{
			return id;
		}
	}
}