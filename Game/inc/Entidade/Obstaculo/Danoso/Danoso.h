#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Danoso : public Obstaculo
	{
	protected:
		static const bool attacker = true;
		static const bool retardant = false;

	public:
		Danoso();
		virtual ~Danoso();

		bool getAttacker() const /*override*/;
		bool getRetardant() const /*override*/;
	};
}