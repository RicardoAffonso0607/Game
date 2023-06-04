#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	protected:
		Arma* pArma = nullptr;

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();
	};
}