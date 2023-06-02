#pragma once

#include "Entidade/Obstaculo/Obstaculo.h"

namespace Obstaculos {
	class Retardante : public Obstaculo
	{
	private:
		int slowness;

	public:
		Retardante();
		virtual ~Retardante();
	};
}