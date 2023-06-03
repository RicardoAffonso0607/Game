#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	namespace Chefoes {
		class Nidogue : public Chefao
		{
		private:
			static const unsigned int id;

		public:
			Nidogue(sf::Vector2f pos);
			~Nidogue();

			unsigned int getId() const override;
		};
	}
}