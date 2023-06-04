#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"

namespace Inimigos {
	namespace Chefoes {
		Apofis::Apofis(sf::Vector2f pos)
		{
			body.setSize(sf::Vector2f(400.f, 280.f));
			body.setPosition(pos);
		}

		Apofis::~Apofis()
		{
		}

		unsigned int Apofis::getId() const
		{
			return id;
		}


	}
}