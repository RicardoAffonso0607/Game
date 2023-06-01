#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataforma {
	class Areal : public Plataforma
	{
	private:

	public:
		Areal(sf::Vector2f pos, int id);
		~Areal();
	};
}