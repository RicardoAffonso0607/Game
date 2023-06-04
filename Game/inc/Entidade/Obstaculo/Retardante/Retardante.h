#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Retardante : public Obstaculo
	{
	protected:
		static const bool attacker;
		static const bool retardant;

	public:
		Retardante();
		virtual ~Retardante();

		bool getAttacker() const override;
		bool getRetardant() const override;
	};
}