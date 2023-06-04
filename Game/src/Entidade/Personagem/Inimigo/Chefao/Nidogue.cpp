#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"

namespace Inimigos {
	namespace Chefoes {
		Nidogue::Nidogue(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(400.f, 280.f));
			body.setPosition(pos);
		}

		Nidogue::~Nidogue()
		{
		}

		unsigned int Nidogue::getId() const
		{
			return id;
		}
	}
}