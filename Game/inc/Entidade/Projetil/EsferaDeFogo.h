#pragma once

#include "Entidade/Projetil/Projetil.h"

namespace Projeteis {
	class EsferaDeFogo : public Projetil
	{
	private:
		const int damage;

	public:
		EsferaDeFogo(sf::Vector2f pos, int id);
		~EsferaDeFogo();
	};
}