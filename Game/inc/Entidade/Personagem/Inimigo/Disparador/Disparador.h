#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Disparador : public Inimigo
	{
	protected:
		Projetil* pProjetil = nullptr;

	public:
		Disparador();
		virtual ~Disparador();
	};
}