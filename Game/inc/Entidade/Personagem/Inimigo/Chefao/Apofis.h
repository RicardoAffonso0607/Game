#pragma once

#include "Entidade/Personagem/Inimigo/Chefao/Chefao.h"
#include "Entidade/Projetil/EsferaDeFogo.h"
#include "Lista/ListaEntidades.h"

namespace Inimigos {
	namespace Chefoes {
		class Apofis : public Chefao
		{
		private:
			static const unsigned int id;

			static const float mass;// massa

			static const sf::Vector2f vel_max;// velocidade máxima

			Projeteis::EsferaDeFogo* fogo;// projetil de fogo

			ListaEntidades* list_ent;// lista de entidades

			sf::SoundBuffer fire_cast;// som do disparo

		public:
			Apofis(sf::Vector2f pos, ListaEntidades* list);
			~Apofis();

			unsigned int getId() const override;

			float getMass() const override;// massa?

			void attack() override;// ataca
		};
	}
}