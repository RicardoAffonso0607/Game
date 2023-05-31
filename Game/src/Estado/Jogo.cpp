#include "pch.h"
#include "Estado/Jogo.h"

Jogo::Jogo() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos())
{
	inicializa();
	executar();
}


void Jogo::inicializa()
{
	fase1 = new Estado::Floresta;
	fase2 = new Estado::Deserto;

	if (ger_grafico == NULL)
	{
		cout << "Gerenciador gráfico nulo" << endl;
		exit(1);
	}

	if (ger_eventos == NULL)
	{
		cout << "Gerenciador de eventos nulo" << endl;
		exit(1);
	}
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	while (ger_grafico->verificaJanelaAberta())
	{
		ger_eventos->executar();
		ger_grafico->limpaJanela();

		//fase1->executar();
		fase2->executar();

		ger_grafico->mostraElementos();
	}
}

