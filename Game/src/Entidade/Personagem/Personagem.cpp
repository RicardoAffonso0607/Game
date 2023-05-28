#include "pch.h"
#include "../../../inc/Entidade/Personagem/Personagem.h"

Personagem::Personagem(sf::Vector2f pos, int id) : EntidadeMovel(id, pos), life(100), damage(5)
{
}

Personagem::~Personagem()
{
}
