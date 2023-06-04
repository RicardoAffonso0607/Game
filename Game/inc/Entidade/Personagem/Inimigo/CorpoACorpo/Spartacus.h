#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"
#include "Entidade/Arma/Espada.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Spartacus : public CorpoACorpo
		{
		private:
			static const int life;

			static const unsigned int id;

		public:
			Spartacus(sf::Vector2f pos);
			~Spartacus();

			unsigned int getId() const override;
		};
	}
}