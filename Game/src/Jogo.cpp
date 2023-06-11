#include "pch.h"
#include "Jogo.h"

Jogo::Jogo() :
	ger_grafico(ger_grafico->getGrafico()),
	ger_eventos(ger_eventos->getEventos()),
	ger_salvamento(ger_salvamento->getSalvamento()),
	iniciar(0)
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
	ranking = new Menu::Ranking;

	if (ger_grafico == nullptr)
	{
		string erro = "Gerenciador gráfico nulo.";
		try { throw runtime_error(erro); }
		catch (...) {
			cerr << erro << endl;
			exit(1);
		}
	}

	if (ger_eventos == nullptr)
	{
		string erro = "Gerenciador de eventos nulo.";
		try { throw runtime_error(erro); }
		catch (...) {
			cerr << erro << endl;
			exit(1);
		}
	}


	if (ger_salvamento == nullptr)
	{
		string erro = "Gerenciador de salvamento nulo.";
		try { throw runtime_error(erro); }
		catch (...) {
			cerr << erro << endl;
			exit(1);
		}
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
		else if (iniciar == 3)
			iniciar = ranking->executar();
		else if (iniciar == 4)
			iniciar = morte->executar();


		ger_grafico->setCamera();
		ger_grafico->mostraElementos();
	}
}

