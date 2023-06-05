#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Faca : public Arma
	{
	private:
		static const int damage;// dano que causa

		static const unsigned int id;

		bool attacker;

		Entidade* pColidiu;

	public:
		Faca(sf::Vector2f pos);
		~Faca();

		bool getAttacker() const override;// está atacando?

		int getDamage() const override;// dano que causa?

		unsigned int getId() const override;// id?

		void attack() override;// ataca
		void setAttacker()/* override*/;// atacar
	};
}