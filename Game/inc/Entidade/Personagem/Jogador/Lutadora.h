#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Jogadores {
	class Lutadora : public Jogador
	{
	private:
		static const unsigned int id;

		static const float mass;

		static const sf::Vector2f vel_max;

		int life;

		sf::Vector2f vel;

	public:
		Lutadora(sf::Vector2f pos, int pl_life);
		~Lutadora();

		sf::Vector2f getVel() const override;

		unsigned int getId() const override;

		float getMass() const override;
	};
}