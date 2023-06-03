#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Inerte : public Obstaculo
	{
	protected:
		static const bool retardant;
		static const bool attacker;

	public:
		Inerte();
		virtual ~Inerte();

		bool getRetardant() const override;
		bool getAttacker() const override;
	};
}