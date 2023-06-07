#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Espada : public Arma
	{
	private:
		static const int damage;// dano que causa

		static const unsigned int id;

		bool attacker;

		Entidade* pColidiu;

		sf::SoundBuffer swoosh;

		sf::SoundBuffer hit;

		sf::Sound sfx2;

		float angle = 40.f;

	public:
		Espada(sf::Vector2f pos);
		~Espada();

		bool getAttacker() const override;// está atacando?

		int getDamage() const override;// dano que causa?

		unsigned int getId() const override;// id?

		void attack() override;// ataca
	};
}