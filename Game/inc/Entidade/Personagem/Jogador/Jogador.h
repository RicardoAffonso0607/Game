#pragma once

#include "../Personagem.h"

class Jogador : public Personagem
{
private:
	bool paraDireita;
	bool paraCima;
	bool podeMover;
	bool podePular;

public:

	Jogador(sf::Vector2f pos, int id, int life);
	~Jogador();

	void move();
	void alteraDirecaoX(bool direita) { this->paraDireita = direita; }
	void alteraDirecaoY(bool cima) { this->paraCima = cima; }
	void podeMoverX(bool verdade) { this->podeMover = verdade; }
	void podeMoverY(bool verdade) { this->podePular = verdade; }
	void attack();

	sf::Vector2f getPos() { return pos; }
};

