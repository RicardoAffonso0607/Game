#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"

class Jogo
{
private:
	sf::RenderWindow window;
	Jogador* jogador1;

public:
	Jogo();
	~Jogo();

	void executar();

	void setJogador(Jogador* pJg) { jogador1 = pJg; }
	Jogador* getJogador() { return jogador1; }

	void eventos();
	void teclas_pressionadas();
};

