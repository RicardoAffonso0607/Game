#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Retardante : public Obstaculo
	{
	protected:
		static const bool retardant;
		static const bool attacker;

	public:
		Retardante();
		virtual ~Retardante();

		bool getRetardant() const override;
		bool getAttacker() const override;
	};
}