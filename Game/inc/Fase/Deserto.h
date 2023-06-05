#pragma once

#include "Fase/Fase.h"

namespace Fases {
	class Deserto : public Fase
	{
	private:
		Jogador* j1;
	public:
		Deserto();
		~Deserto();

		void executar();
		void criarJogador();
		void criarInimigos();
		void criarObstaculos();
	};
}