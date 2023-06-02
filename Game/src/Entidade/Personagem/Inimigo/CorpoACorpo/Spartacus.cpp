#include "pch.h"
#include "Entidade/Personagem/Inimigo/CorpoACorpo/Spartacus.h"

namespace Inimigos {
	namespace CorpoACorpos {
		Spartacus::Spartacus(sf::Vector2f pos, int id)
		{
			body.setPosition(pos);
		}

		Spartacus::~Spartacus()
		{

		}
	}
}