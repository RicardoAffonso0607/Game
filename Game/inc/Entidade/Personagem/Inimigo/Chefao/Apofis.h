#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	namespace Chefoes {
		class Apofis : public Chefao
		{
		private:
			static const unsigned int id;

		public:
			Apofis(sf::Vector2f pos);
			~Apofis();

			unsigned int getId() const override;
		};
	}
}