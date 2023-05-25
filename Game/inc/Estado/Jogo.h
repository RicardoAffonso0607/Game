#pragma once

#include "../Entidade/Personagem/Jogador/Jogador.h"
#include "../Lista/ListaEntidades.h"
#include "../Entidade/Personagem/Inimigos/EnemyMelee.h"

class Jogo
{
private:
	sf::RenderWindow window;
	ListaEntidades list_ent;
	Jogador* jogador1;
	EnemyMelee* enemy1;

public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();

	void setJogador(Jogador* pJg) { jogador1 = pJg; }
	Jogador* getJogador() { return jogador1; }

	void eventos();
	void teclas_pressionadas();

};

