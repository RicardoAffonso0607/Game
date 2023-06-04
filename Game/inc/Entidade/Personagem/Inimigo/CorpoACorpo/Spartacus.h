#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"
#include "Entidade/Arma/Espada.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Spartacus : public CorpoACorpo
		{
		private:
			static const unsigned int id;

			static const float mass;

			static const sf::Vector2f vel_max;

		public:
			Spartacus(sf::Vector2f pos);
			~Spartacus();

			unsigned int getId() const override;

			float getMass() const override;
		};
	}
}