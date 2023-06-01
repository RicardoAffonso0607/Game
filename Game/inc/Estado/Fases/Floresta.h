#pragma once

#include "Estado/Fases/Fase.h"

namespace Estado
{
	class Floresta : public Fase
	{
	private:
		Jogador* j1;
	public:
		Floresta();
		~Floresta();

		void executar();
		void criarJogador();
		void criarInimigos();
		void criarObstaculos();
		
	};

}

