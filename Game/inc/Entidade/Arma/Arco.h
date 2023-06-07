#pragma once

#include "Entidade/Arma/Arma.h"
#include "Entidade/Projetil/Flecha.h"
#include "Lista/ListaEntidades.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		static const bool attacker;// ataca?

		static const float cast_height;// altura do disparo

		static const unsigned int id;

		Projeteis::Flecha* flecha;// ponteiro da flecha
		
		ListaEntidades* list_ent;// lista de entidades

		sf::SoundBuffer bow_release;// som do disparo

	public:
		Arco(sf::Vector2f pos, ListaEntidades* list);
		~Arco();

		unsigned int getId() const override;// id?

		void attack() override;// atacar

		bool getAttacker() const override;// é atacante?

		void resetRot() override;
	};
}