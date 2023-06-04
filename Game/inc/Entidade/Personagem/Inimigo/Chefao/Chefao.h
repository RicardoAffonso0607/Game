#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Chefao : public Inimigo
	{
	protected:
		Projetil* pProjetil = nullptr;

	public:
		Chefao();
		virtual ~Chefao();
	};
}