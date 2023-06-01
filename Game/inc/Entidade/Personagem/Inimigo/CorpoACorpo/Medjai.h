#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigo {
	namespace CorpoACorpo {
		class Medjai : public CorpoACorpo
		{
		private:

		public:
			Medjai(sf::Vector2f pos, int id);
			~Medjai();
		};
	}
}