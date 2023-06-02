#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataformas {
	class Gramado : public Plataforma
	{
	private:

	public:
		Gramado(sf::Vector2f pos, int id);
		~Gramado();
	};
}