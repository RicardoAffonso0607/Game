#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	private:
		Arma* pArma;

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();
	};
}