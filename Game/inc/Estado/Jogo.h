#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Lista/ListaEntidades.h"
#include "Entidade/Personagem/Inimigos/EnemyMelee.h"
#include "Entidade/Obstaculos/Plataforma.h"
#include "Estado/Fase.h"
#include "Gerenciador/Colisao.h"

class Jogo
{
private:
	sf::RenderWindow window;
	Jogador* jogador1;
	EnemyMelee* enemy1;
	Plataforma* platform1;
	Plataforma* platform2;

protected:
	ListaEntidades* list_ent;
	Gerenciador::Colisao* colisor;

public:
	Jogo();
	~Jogo();

	void executar();

	void setJogador(Jogador* pJg) { jogador1 = pJg; }
	Jogador* getJogador() { return jogador1; }

	void eventos();
	void teclas_pressionadas();
};

