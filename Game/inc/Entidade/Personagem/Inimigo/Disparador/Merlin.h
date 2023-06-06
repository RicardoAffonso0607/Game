#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"
#include "Entidade/Projetil/EsferaDeGelo.h"
#include "Lista/ListaEntidades.h"

namespace Inimigos {
	namespace Disparadores {
		class Merlin : public Disparador
		{
		private:
			static const unsigned int id;

			static const float mass;// massa

			static const sf::Vector2f vel_max;// velocidade máxima

			Projeteis::EsferaDeGelo* gelo;// projetil de gelo

			ListaEntidades* list_ent;// lista de entidades

			sf::SoundBuffer ice_cast;// som do disparo

		public:
			Merlin(sf::Vector2f pos, ListaEntidades* list);
			~Merlin();

			unsigned int getId() const override;

			float getMass() const override;// massa?

			void attack() override;// ataca
		};
	}
}