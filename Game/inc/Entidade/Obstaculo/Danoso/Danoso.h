#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Danoso : public Obstaculo
	{
	protected:
		static const bool retardant;
		static const bool attacker;

	public:
		Danoso();
		virtual ~Danoso();

		bool getRetardant() const override;
		bool getAttacker() const override;
	};
}