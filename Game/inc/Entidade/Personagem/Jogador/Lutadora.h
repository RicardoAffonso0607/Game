#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Lutadora : public Jogador
	{
	private:
		static const unsigned int id;

		static float mass;

		static const sf::Vector2f vel_max;

	public:
		Lutadora(sf::Vector2f pos, int pl_life);
		~Lutadora();

		unsigned int getId() const override;

		float getMass() const override;
	};
}