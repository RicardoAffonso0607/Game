#pragma once

#include "Entidade/Personagem/Inimigo/Disparador/Disparador.h"
#include "Entidade/Projetil/EsferaDeFogo.h"
#include "Lista/ListaEntidades.h"

namespace Inimigos {
	namespace Disparadores {
		class Horus : public Disparador
		{
		private:
			static const unsigned int id;

			static const float mass;// massa

			static const sf::Vector2f vel_max;// velocidade máxima

			Projeteis::EsferaDeFogo* fogo;// projetil de fogo

			ListaEntidades* list_ent;// lista de entidades

			sf::SoundBuffer fire_cast;// som do disparo

		public:
			Horus(sf::Vector2f pos, ListaEntidades* list);
			~Horus();

			unsigned int getId() const override;

			float getMass() const override;// massa?

			void attack() override;// ataca
		};
	}
}