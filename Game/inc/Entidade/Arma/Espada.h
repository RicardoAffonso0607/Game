#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Espada : public Arma
	{
	private:
		const int damage = 5;

		static const int id = 93;

		const sf::Time delay = sf::milliseconds(500);

	public:
		Espada(sf::Vector2f pos, Personagem* pPer);
		~Espada();

		int getDamage() const /*override*/;

		unsigned int getId() const override;

		sf::Time getDelay() const /*override*/;
	};
}