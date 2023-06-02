#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Nidogue.h"

namespace Inimigos {
	namespace Chefoes {
		Nidogue::Nidogue(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Nidogue::~Nidogue()
		{

		}
	}
}