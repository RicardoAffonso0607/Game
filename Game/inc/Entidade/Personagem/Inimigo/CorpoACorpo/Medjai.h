#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"
#include "Entidade/Arma/Faca.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Medjai : public CorpoACorpo
		{
		private:
			static const int life;

			static const unsigned int id;

		public:
			Medjai(sf::Vector2f pos);
			~Medjai();

			unsigned int getId() const override;
		};
	}
}