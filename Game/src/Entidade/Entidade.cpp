#include "pch.h"
#include "Entidade/Entidade.h"
#include "Gerenciador/Grafico.h"

Entidade::Entidade(int id) : Ente()
{
	id = id;

	vel_max = sf::Vector2f(10.f, 10.f);
	size_max = sf::Vector2f(200.f, 200.f);



	movable = false;
	retarder = false;
	attacker = false;
	damageable = false;
	projected = false;
	attack_delay = NULL;
	retarder_delay = NULL;
	retarder_timer = NULL;
}

Entidade::~Entidade()
{
}
