#pragma once

#include "Entidade/Plataforma/Plataforma.h"

namespace Plataformas {
	class Gramado : public Plataforma
	{
	private:

	public:
		Gramado(sf::Vector2f plat_pos, sf::Vector2f plat_size, int id);
		~Gramado();
	};
}