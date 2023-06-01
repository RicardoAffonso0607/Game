#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projetil {
	class EsferaDeGelo : public Projetil
	{
	private:

	public:
		EsferaDeGelo(sf::Vector2f pos, int id);
		~EsferaDeGelo();
	};
}