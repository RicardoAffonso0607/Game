#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogador {
	class Ninja : public Jogador
	{
	private:

	public:
		Ninja(sf::Vector2f pos, int id, float life);
		~Ninja();
	};
}