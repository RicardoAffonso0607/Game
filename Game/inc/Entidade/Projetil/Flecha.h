#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projetil {
	class Flecha : public Projetil
	{
	private:

	public:
		Flecha(sf::Vector2f pos, int id);
		~Flecha();
	};
}