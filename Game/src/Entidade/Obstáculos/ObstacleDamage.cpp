#include "pch.h"
#include "../../Game/inc/Entidade/Obst�culos/ObstacleDamage.h"

ObstacleDamage::ObstacleDamage(sf::Vector2f pos, int id) : Obstacles(pos, id), damage(1)
{
}

ObstacleDamage::~ObstacleDamage()
{
}
