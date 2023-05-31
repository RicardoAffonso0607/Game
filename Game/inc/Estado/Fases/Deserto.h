#pragma once

#include "Estado/Fases/Fase.h"

namespace Estado
{
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

