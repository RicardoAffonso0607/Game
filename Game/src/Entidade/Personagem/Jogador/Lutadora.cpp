#include "pch.h"
#include "Entidade/Personagem/Jogador/Lutadora.h"

namespace Jogador {
	Lutadora::Lutadora(sf::Vector2f pos, int id, float life) : Jogador(pos, id, life)
	{
		textura.loadFromFile("Game/assets/teste.png");
		body.setTexture(&textura);
		body.setPosition(pos);
	}

	Lutadora::~Lutadora()
	{

	}
}