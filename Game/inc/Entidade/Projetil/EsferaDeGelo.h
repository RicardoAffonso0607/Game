#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeGelo : public Projetil
	{
	private:
		const int damage;

	public:
		EsferaDeGelo(sf::Vector2f pos, int id);
		~EsferaDeGelo();
	};
}