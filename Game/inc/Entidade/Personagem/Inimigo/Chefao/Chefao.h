#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Chefao : public Inimigo
	{
	private:
		Projetil* pProjetil;

	public:
		Chefao();
		virtual ~Chefao();
	};
}