#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projetil {
	class EsferaDeFogo : public Projetil
	{
	private:

	public:
		EsferaDeFogo(sf::Vector2f pos, int id);
		~EsferaDeFogo();
	};
}