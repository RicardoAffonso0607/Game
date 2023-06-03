#include "pch.h"
#include "Entidade/Personagem/Inimigo/Chefao/Apofis.h"

namespace Inimigos {
	namespace Chefoes {
		Apofis::Apofis(sf::Vector2f pos) :
			id(51),
			life(100),
			size(sf::Vector2f(400.f, 280.f))
		{
			body.setSize(size);
			body.setPosition(pos);
		}

		Apofis::~Apofis()
		{
		}
	}
}