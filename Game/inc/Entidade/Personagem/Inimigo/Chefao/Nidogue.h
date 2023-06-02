#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	namespace Chefoes {
		class Nidogue : public Chefao
		{
		private:

		public:
			Nidogue(sf::Vector2f pos, int id);
			~Nidogue();
		};
	}
}