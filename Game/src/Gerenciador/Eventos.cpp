#include "pch.h"
#include "../../inc/Gerenciador/Eventos.h"

Gerenciador::Eventos* Gerenciador::Eventos::pEventos(NULL);

Gerenciador::Eventos::Eventos() : pGrafico(pGrafico->getGrafico()), pJogador(NULL)
{
}

Gerenciador::Eventos::~Eventos()
{
	pGrafico = NULL;
	pJogador = NULL;
}

Gerenciador::Eventos* Gerenciador::Eventos::getEventos()
{
	if (pEventos == NULL)
		pEventos = new Gerenciador::Eventos();

	return pEventos;

}

void Gerenciador::Eventos::executar()
{
	sf::Event evento;

	while (pGrafico->getWindow()->pollEvent(evento))
	{
		if (evento.type == sf::Event::KeyPressed)
			verificaTeclaPressionada(evento.key.code);
		else if (evento.type == sf::Event::Closed)
			pGrafico->fecharJanela();

	}
}

void Gerenciador::Eventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::A)
	{
		pJogador->alteraDirecaoX(false);
		pJogador->podeMoverX(true);
	}
	else if (tecla == sf::Keyboard::D)
	{
		pJogador->alteraDirecaoX(true);
		pJogador->podeMoverX(true);
	}

	if (tecla == sf::Keyboard::W)
	{
		pJogador->alteraDirecaoY(true);
		pJogador->podeMoverY(true);
	}
	else if (tecla == sf::Keyboard::S)
	{
		pJogador->alteraDirecaoY(false);
		pJogador->podeMoverY(true);
	}

	if (tecla == sf::Keyboard::Escape)
	{
		pGrafico->fecharJanela();
	}
}
