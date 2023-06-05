#include "pch.h"
#include "Jogo.h"

Jogo::Jogo() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos())
{
	inicializa();
	executar();
}


void Jogo::inicializa()
{
	fase1 = new Fase::Floresta;
	fase2 = new Fase::Deserto;

	if (ger_grafico == nullptr)
	{
		cout << "Gerenciador gráfico nulo" << endl;
		exit(1);
	}

	if (ger_eventos == nullptr)
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

		fase1->executar();
		//fase2->executar();

		ger_grafico->setCamera();
		ger_grafico->mostraElementos();
	}
}

