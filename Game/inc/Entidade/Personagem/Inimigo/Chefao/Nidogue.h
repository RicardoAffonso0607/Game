#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"

namespace Inimigos {
	namespace Chefoes {
		class Nidogue : public Chefao
		{
		private:
			static const unsigned int id;

			static const float mass;

			static const sf::Vector2f vel_max;

		public:
			Nidogue(sf::Vector2f pos);
			~Nidogue();

			unsigned int getId() const override;

			float getMass() const override;
		};
	}
}