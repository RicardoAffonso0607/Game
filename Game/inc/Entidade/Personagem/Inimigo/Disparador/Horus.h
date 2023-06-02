#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Horus : public Disparador
		{
		private:

		public:
			Horus(sf::Vector2f pos, int id);
			~Horus();
		};
	}
}