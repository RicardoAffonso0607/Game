#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeGelo : public Projetil
	{
	private:
		const int damage;

		const sf::Vector2f size;

	public:
		EsferaDeGelo(sf::Vector2f pos, int id);
		~EsferaDeGelo();

		void getDamage() const;
	};
}