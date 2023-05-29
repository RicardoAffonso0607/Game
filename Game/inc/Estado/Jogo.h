#pragma once

#include "../Entidade/Personagem/Jogador/Jogador.h"
#include "../Lista/ListaEntidades.h"
#include "../Entidade/Personagem/Inimigos/EnemyMelee.h"
#include "../Gerenciador/Grafico.h"
#include "../Gerenciador/Eventos.h"

class Jogo
{
private:
	Gerenciador::Grafico* ger_grafico;
	Gerenciador::Eventos* ger_eventos;
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

};

