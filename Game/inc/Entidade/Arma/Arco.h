#pragma once

#include "Entidade/Arma/Arma.h"
#include "Entidade/Projetil/Flecha.h"
#include "Lista/ListaEntidades.h"

namespace Armas {
	class Arco : public Arma
	{
	private:
		static const bool attacker;// ataca?

		static const unsigned int id;

		Projeteis::Flecha* flecha;
		
		ListaEntidades* list_ent;

	public:
		Arco(sf::Vector2f pos, ListaEntidades* list);
		~Arco();

		unsigned int getId() const override;// id?

		void attack() override;// atacar

		bool getAttacker() const override;// é atacante?
	};
}