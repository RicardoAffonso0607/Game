#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeGelo : public Projetil
	{
	private:
		static const int damage;

		static const sf::Vector2f size;

	public:
		EsferaDeGelo(sf::Vector2f pos, int id);
		~EsferaDeGelo();

		int getDamage() const;
	};
}
