#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Lutadora : public Jogador
	{
	private:

	public:
		Lutadora(sf::Vector2f pos, float pl_life, int id);
		~Lutadora();
	};
}