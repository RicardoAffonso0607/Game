#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Merlin : public Disparador
		{
		private:
			static const unsigned int id;

		public:
			Merlin(sf::Vector2f pos);
			~Merlin();

			unsigned int getId() const override;
		};
	}
}