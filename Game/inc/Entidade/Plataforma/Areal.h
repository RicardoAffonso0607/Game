#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataformas {
	class Areal : public Plataforma
	{
	private:

	public:
		Areal(sf::Vector2f pos, int id);
		~Areal();
	};
}