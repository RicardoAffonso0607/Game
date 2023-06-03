#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Disparador : public Inimigo
	{
	private:
		Projetil* pProjetil;

	public:
		Disparador();
		virtual ~Disparador();
	};
}