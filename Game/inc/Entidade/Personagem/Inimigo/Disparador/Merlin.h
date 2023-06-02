#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Merlin : public Disparador
		{
		private:

		public:
			Merlin(sf::Vector2f pos, int id);
			~Merlin();
		};
	}
}