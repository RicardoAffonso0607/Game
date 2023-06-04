#pragma once

#include "Entidade/Arma/Arma.h"

namespace Armas {
	class Faca : public Arma
	{
	private:
		const int damage = 2;

		static const int id = 92;

		const sf::Time delay = sf::milliseconds(400);

	public:
		Faca(sf::Vector2f pos, Personagem* pPer);
		~Faca();

		int getDamage() const /*override*/;

		unsigned int getId() const override;

		sf::Time getDelay() const /*override*/;
	};
}