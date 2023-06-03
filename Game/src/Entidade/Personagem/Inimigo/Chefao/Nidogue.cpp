#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"

namespace Inimigos {
	namespace Chefoes {
		Nidogue::Nidogue(sf::Vector2f pos, int id) :
			life(200),
			size(sf::Vector2f(400.f, 280.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Nidogue::~Nidogue()
		{
		}
	}
}