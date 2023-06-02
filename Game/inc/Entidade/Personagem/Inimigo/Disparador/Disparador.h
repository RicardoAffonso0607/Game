#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"

namespace Inimigos {
	class Disparador : public Inimigo
	{
	private:
		//Projetil* magic;

	public:
		Disparador();
		virtual ~Disparador();

		void move();
		void attack();
	};
}