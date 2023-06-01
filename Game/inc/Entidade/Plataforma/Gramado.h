#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataforma {
	class Gramado : public Plataforma
	{
	private:

	public:
		Gramado(sf::Vector2f pos, int id);
		~Gramado();
	};
}