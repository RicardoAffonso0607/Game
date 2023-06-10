#include "pch.h"
#include "Jogo.h"

Jogo::Jogo() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos()), iniciar(0)
{
	inicializa();
	executar();
}


void Jogo::inicializa()
{
	fase1 = new Fases::Deserto;
	fase2 = new Fases::Floresta;
	menu = new Menu::Menu;
	morte = new Menu::Morte;

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

		if (iniciar == 0)
			iniciar = menu->executar();
		else if (iniciar == 1)
			iniciar = fase1->executar();
		else if (iniciar == 2)
			iniciar = fase2->executar();
		else if (iniciar == 3);
		//iniciar = ranking->executar
		else if (iniciar == 4)
			iniciar = morte->executar();


		ger_grafico->setCamera();
		ger_grafico->mostraElementos();
	}
}

