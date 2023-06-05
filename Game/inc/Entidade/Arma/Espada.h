#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Espada : public Arma
	{
	private:
		static const int damage;// dano que causa

		static const unsigned int id;

		bool attacker;

	public:
		Espada(sf::Vector2f pos);
		~Espada();

		bool getAttacker() const override;// está atacando?

		int getDamage() const override;// dano que causa?

		unsigned int getId() const override;// id?

		//void attack() override;// ataca
		void setAttacker()/* override*/;// atacar
	};
}