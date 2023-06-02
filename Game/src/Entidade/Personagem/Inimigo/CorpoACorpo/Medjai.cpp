#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Medjai.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Medjai::Medjai(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Medjai::~Medjai()
		{

		}
	}
}