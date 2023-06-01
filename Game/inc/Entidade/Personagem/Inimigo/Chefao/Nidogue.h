#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigo {
	namespace Chefao {
		class Nidogue : public Chefao
		{
		private:

		public:
			Nidogue(sf::Vector2f pos, int id);
			~Nidogue();
		};
	}
}