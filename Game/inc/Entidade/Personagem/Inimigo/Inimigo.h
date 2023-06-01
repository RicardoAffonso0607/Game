#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

namespace Inimigo {
	class Inimigo : public Personagem
	{
	protected:
		static Jogador::Jogador* pPlayer;

	public:
		Inimigo(sf::Vector2f pos, int id);
		~Inimigo();

		virtual void move() = 0;
		virtual void attack() = 0;

		static void setPlayer(Jogador::Jogador* pPla);
		Jogador::Jogador* getPlayer() { return pPlayer; }
	};
}