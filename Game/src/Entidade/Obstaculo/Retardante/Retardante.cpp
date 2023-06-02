#include "pch.h"
#include "Entidade/Obstaculo/Retardante/Retardante.h"

namespace Obstaculos {
	Retardante::Retardante()
	{
		movable = false;
		attacker = false;
		retarder = true;
		damageable = false;
	}

	Retardante::~Retardante()
	{

	}
}