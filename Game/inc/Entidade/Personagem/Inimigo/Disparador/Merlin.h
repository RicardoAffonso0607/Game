#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Merlin : public Disparador
		{
		private:
			static const int life = 80;

			static const unsigned int id = 72;

		public:
			Merlin(sf::Vector2f pos);
			~Merlin();

			unsigned int getId() const override;
		};
	}
}