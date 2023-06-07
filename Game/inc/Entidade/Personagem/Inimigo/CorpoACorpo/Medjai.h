#pragma once

#include "Entidade/Personagem/Inimigo/CorpoACorpo/CorpoACorpo.h"
#include "Entidade/Arma/Faca.h"
#include "Lista/ListaEntidades.h"

namespace Inimigos {
	namespace CorpoACorpos {
		class Medjai : public CorpoACorpo
		{
		private:
			static const unsigned int id;

			static const float mass;

			static const sf::Vector2f vel_max;

		public:
			Medjai(sf::Vector2f pos, ListaEntidades* list_ent);
			~Medjai();

			unsigned int getId() const override;

			float getMass() const override;
		};
	}
}