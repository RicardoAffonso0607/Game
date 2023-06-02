#include "pch.h"
#include "Entidade/Obstaculo/Danoso/Danoso.h"

namespace Obstaculos {
	Danoso::Danoso()
	{
		movable = false;
		attacker = true;
		retarder = false;
		damageable = false;
	}

	Danoso::~Danoso()
	{

	}
}