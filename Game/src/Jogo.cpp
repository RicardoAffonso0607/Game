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
			fase1->executar();
		else if (iniciar == 2)
			fase2->executar();
		//switch (iniciar)
		//{
		//case(0):
			//iniciar = menu->executar();
		//case(1):
			//fase1->executar();
		//case(2):
			//fase2->executar();
		//}

		//fase1->executar();
		//fase2->executar();

		ger_grafico->setCamera();
		ger_grafico->mostraElementos();
	}
}

