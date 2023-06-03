#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Ninja : public Jogador
	{
	private:
		static const unsigned int id;

	public:
		Ninja(sf::Vector2f pos, float pl_life);
		~Ninja();

		unsigned int getId() const override;
	};
}