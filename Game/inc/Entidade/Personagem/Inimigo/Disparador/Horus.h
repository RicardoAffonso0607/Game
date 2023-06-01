#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigo {
	namespace Disparador {
		class Horus : public Disparador
		{
		private:

		public:
			Horus(sf::Vector2f pos, int id);
			~Horus();
		};
	}
}