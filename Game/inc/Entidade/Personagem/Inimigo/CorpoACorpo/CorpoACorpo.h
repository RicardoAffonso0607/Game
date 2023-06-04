#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	protected:
		Arma* pArma = nullptr;

		static const bool attacker;

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();

		void move();

		void attack();

		bool getAttacker() const override;
	};
}