#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Danoso : public Obstaculo
	{
	protected:
		static const bool attacker;
		static const bool retardant;

	public:
		Danoso();
		virtual ~Danoso();

		bool getAttacker() const override;
		bool getRetardant() const override;
	};
}