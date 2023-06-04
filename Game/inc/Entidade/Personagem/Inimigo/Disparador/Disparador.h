#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Disparador : public Inimigo
	{
	protected:
		Projetil* pProjetil;

		static const bool retardable;

	public:
		Disparador();
		virtual ~Disparador();

		void move() override;

		void attack() override;

		bool getRetardable() const override;
	};
}