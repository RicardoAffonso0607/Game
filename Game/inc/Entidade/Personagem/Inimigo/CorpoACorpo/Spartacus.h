#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Spartacus : public CorpoACorpo
		{
		private:

		public:
			Spartacus(sf::Vector2f pos, int id);
			~Spartacus();
		};
	}
}