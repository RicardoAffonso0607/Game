#pragma once

#include "Entidade/Personagem/Jogador/Jogador.h"
#include "Entidade/Personagem/Inimigos/EnemyMelee.h"
#include "Entidade/Obstaculos/Plataforma.h"
#include "Entidade/Obstaculos/ObstacleBlock.h"
#include "Lista/ListaEntidades.h"
#include "Estado/Fase.h"
#include "Gerenciador/Colisao.h"
#include "Gerenciador/Grafico.h"
#include "Gerenciador/Eventos.h"

class Jogo
{
private:
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
	Gerenciador::Colisao* colisor;
	ListaEntidades* list_ent;
	Jogador* jogador1;
	EnemyMelee* enemy1;
	Plataforma* platform1;
	Plataforma* platform2;
	Obstacles* obstacle1;

public:
	Jogo();
	~Jogo();

	void inicializa();
	void executar();

	void setJogador(Jogador* pJg) { jogador1 = pJg; }
	Jogador* getJogador() { return jogador1; }

};

