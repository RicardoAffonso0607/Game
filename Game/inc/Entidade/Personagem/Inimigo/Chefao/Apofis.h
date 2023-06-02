#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	namespace Chefoes {
		class Apofis : public Chefao
		{
		private:

		public:
			Apofis(sf::Vector2f pos, int id);
			~Apofis();
		};
	}
}