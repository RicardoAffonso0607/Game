#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Spartacus : public CorpoACorpo
		{
		private:
			static const int life = 50;

			static const unsigned int id = 62;

		public:
			Spartacus(sf::Vector2f pos);
			~Spartacus();

			unsigned int getId() const override;
		};
	}
}