#pragma once

#include "Entidade/Personagem/Inimigo/Inimigo.h"
#include "Entidade/Projetil/Projetil.h"

namespace Inimigos {
	class Chefao : public Inimigo
	{
	protected:
		Projetil* pProjetil;

		static const bool retardable;

	public:
		Chefao();
		virtual ~Chefao();

		void move() override;

		void attack() override;

		bool getRetardable() const override;
	};
}