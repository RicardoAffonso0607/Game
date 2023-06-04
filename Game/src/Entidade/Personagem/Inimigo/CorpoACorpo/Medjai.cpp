#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Medjai::Medjai(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(80.f, 150.f));
			body.setPosition(pos);
		}

		Medjai::~Medjai()
		{
		}

		unsigned int Medjai::getId() const
		{
			return id;
		}
	}
}