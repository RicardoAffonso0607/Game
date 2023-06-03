#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Inerte : public Obstaculo
	{
	protected:
		static const bool attacker;
		static const bool retardant;

	public:
		Inerte();
		virtual ~Inerte();

		bool getAttacker() const override;
		bool getRetardant() const override;
	};
}