#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class Flecha : public Projetil
	{
	private:
		const int damage;

	public:
		Flecha(sf::Vector2f pos, int id);
		~Flecha();
	};
}