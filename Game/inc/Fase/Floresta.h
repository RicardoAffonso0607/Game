#pragma once

#include "Fase/Fase.h"

namespace Fases
{
	class Floresta : public Fase
	{
	private:

	public:
		Floresta();
		~Floresta();

		int executar();
		void criarJogador();
		void criarInimigos();
		void criarObstaculos();
		
	};

}

