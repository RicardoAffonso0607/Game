#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Retardante : public Obstaculo
	{
	private:
		float retard;

	public:
		Retardante();
		virtual ~Retardante();
	};
}