#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"

namespace Inimigos {
	namespace Disparadores {
		class Horus : public Disparador
		{
		private:
			static const unsigned int id;

		public:
			Horus(sf::Vector2f pos);
			~Horus();

			unsigned int getId() const override;
		};
	}
}