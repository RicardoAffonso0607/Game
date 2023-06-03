#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Lutadora : public Jogador
	{
	private:
		static const unsigned int id;

	public:
		Lutadora(sf::Vector2f pos, float pl_life);
		~Lutadora();

		unsigned int getId() const override;
	};
}