#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Arma/Arma.h"

namespace Inimigos {
	class CorpoACorpo : public Inimigo
	{
	protected:
		Arma* pArma = nullptr;

		static const bool retardable;

	public:
		CorpoACorpo();
		virtual ~CorpoACorpo();

		void move() override;

		void attack() override;

		bool getRetardable() const override;
	};
}