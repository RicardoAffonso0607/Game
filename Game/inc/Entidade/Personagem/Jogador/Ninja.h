#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Ninja : public Jogador
	{
	private:
		int life;

		static const unsigned int id;

		static const float mass;

	public:
		Ninja(sf::Vector2f pos, int pl_life);
		~Ninja();

		unsigned int getId() const override;
	};
}