#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Medjai : public CorpoACorpo
		{
		private:

		public:
			Medjai(sf::Vector2f pos, int id);
			~Medjai();
		};
	}
}