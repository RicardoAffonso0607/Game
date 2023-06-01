#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigo {
	namespace CorpoACorpo {
		class Spartacus : public CorpoACorpo
		{
		private:

		public:
			Spartacus(sf::Vector2f pos, int id);
			~Spartacus();
		};
	}
}