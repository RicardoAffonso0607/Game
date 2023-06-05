#pragma once

#include "Fase/Fase.h"

namespace Fases {
	class Deserto : public Fase
	{
	private:
	public:
		Deserto();
		~Deserto();

		void executar();
		void criarJogador();
		void criarInimigos();
		void criarObstaculos();
	};
}