#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Lista/ListaEntidades.h"
#include "Entidade/Personagem/Inimigos/EnemyMelee.h"
#include "Estado/Fase.h"

class Jogo
{
private:
	sf::RenderWindow window;
	ListaEntidades *listaEntidades;
	Jogador* jogador1;
	EnemyMelee* enemy1;
	//Fase fase1;
public:
	Jogo();
	~Jogo();

	void executar();

	void setJogador(Jogador* pJg) { jogador1 = pJg; }
	Jogador* getJogador() { return jogador1; }

	void eventos();
	void teclas_pressionadas();
};

