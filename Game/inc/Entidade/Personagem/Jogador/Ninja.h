#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Ninja : public Jogador
	{
	private:

	public:
		Ninja(sf::Vector2f pos, float pl_life, int id);
		~Ninja();
	};
}