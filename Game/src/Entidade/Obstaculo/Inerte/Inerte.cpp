#include "pch.h"
#include "Entidade/Obstaculo/Inerte/Inerte.h"

namespace Obstaculos {
	Inerte::Inerte()
	{
		movable = false;
		attacker = false;
		retarder = false;
		damageable = false;

		body.setFillColor(sf::Color::Green);
		body.setPosition(pos);
	}

	Inerte::~Inerte()
	{

	}
}