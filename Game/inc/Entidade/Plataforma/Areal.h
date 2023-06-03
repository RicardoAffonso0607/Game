#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataformas {
	class Areal : public Plataforma
	{
	private:

	public:
		Areal(sf::Vector2f pos, sf::Vector2f size, int id);
		~Areal();
	};
}