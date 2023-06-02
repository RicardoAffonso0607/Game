#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"

namespace Inimigos {
	namespace Chefoes {
		Apofis::Apofis(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Apofis::~Apofis() {

		}
	}
}