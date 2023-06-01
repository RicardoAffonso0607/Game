#pragma once

#include "Fase/Fase.h"

namespace Fase
{
	class Floresta : public Fase
	{
	private:
		Jogador::Jogador* j1;
	public:
		Floresta();
		~Floresta();

		void executar();
		void criarJogador();
		void criarInimigos();
		void criarObstaculos();
		
	};

}

