#include "pch.h"
#include "Menu/Menu.h"

namespace Menu{
	Menu::Menu() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos()), fase1(new Fases::Deserto), 
		fase2 (new Fases::Floresta)
	{
		ger_grafico->getCamera()->setCenter(ger_grafico->getWindowSize().x / 2, ger_grafico->getWindowSize().y / 2);

		fundo.setPosition(0.f, 0.f);
		fundo.setSize((sf::Vector2f) ger_grafico->getWindowSize());
		fundo.setFillColor(sf::Color::Black);

		if (fonte.loadFromFile("Game/assets/font/SquareGame.otf"))
			printf("Fonte carregada");
		else
			printf("Fonte não carregada");

		AgeOfWarriors.setFont(fonte);
		AgeOfWarriors.setString("Age of Warriors ++");
		AgeOfWarriors.setPosition(580.f, 100.f);
		AgeOfWarriors.setCharacterSize(60);

		Fase1.setFont(fonte);
		Fase1.setString("Fase 1 - Deserto");
		Fase1.setPosition(680.f, 280.f);
		Fase1.setCharacterSize(45);

		Fase2.setFont(fonte);
		Fase2.setString("Fase 2 - Floresta");
		Fase2.setPosition(660.f, 400.f);
		Fase2.setCharacterSize(45);

		Ranking.setFont(fonte);
		Ranking.setString("Ranking");
		Ranking.setPosition(780.f, 520.f);
		Ranking.setCharacterSize(45);

		Sair.setFont(fonte);
		Sair.setString("Sair");
		Sair.setPosition(820.f, 640.f);
		Sair.setCharacterSize(45);

	}

	Menu::~Menu()
	{
	}

	int Menu::executar()
	{

		ger_grafico->getWindow()->setMouseCursorVisible(true);
		ger_grafico->getCamera()->setCenter(ger_grafico->getWindowSize().x / 2, ger_grafico->getWindowSize().y / 2);

		ger_grafico->desenhaElemento(fundo);
		ger_grafico->desenhaElemento(AgeOfWarriors);
		ger_grafico->desenhaElemento(Fase1);
		ger_grafico->desenhaElemento(Fase2);
		ger_grafico->desenhaElemento(Ranking);
		ger_grafico->desenhaElemento(Sair);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (sf::Mouse::getPosition().x > 670 && sf::Mouse::getPosition().x < 1100 &&
				sf::Mouse::getPosition().y > 280 && sf::Mouse::getPosition().y < 420 )
				return 1;

			if (sf::Mouse::getPosition().x > 650 && sf::Mouse::getPosition().x < 1100 &&
				sf::Mouse::getPosition().y > 440 && sf::Mouse::getPosition().y < 540)
				return 2;

			if (sf::Mouse::getPosition().x > 700 && sf::Mouse::getPosition().x < 1100 &&
				sf::Mouse::getPosition().y > 560 && sf::Mouse::getPosition().y < 660)
				return 3;

			if (sf::Mouse::getPosition().x > 700 && sf::Mouse::getPosition().x < 1100 &&
				sf::Mouse::getPosition().y > 640 && sf::Mouse::getPosition().y < 760)
				exit(1);
		}
		return 0;

	}
}