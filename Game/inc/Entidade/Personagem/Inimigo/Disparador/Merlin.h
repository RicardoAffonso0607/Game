#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Merlin : public Disparador
		{
		private:
			static const unsigned int id;

			static const float mass;

			static const sf::Vector2f vel_max;

		public:
			Merlin(sf::Vector2f pos);
			~Merlin();

			unsigned int getId() const override;

			float getMass() const override;
		};
	}
}