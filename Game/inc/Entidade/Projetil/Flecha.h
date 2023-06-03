#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class Flecha : public Projetil
	{
	private:
		const sf::Vector2f size;

	public:
		Flecha(sf::Vector2f pos, int id);
		~Flecha();
	};
}