#include "pch.h"
#include "Menu/Menu.h"

namespace Menu{
	Menu::Menu() : ger_grafico(ger_grafico->getGrafico()), ger_eventos(ger_eventos->getEventos()), fase1(new Fases::Deserto), 
		fase2 (new Fases::Floresta)
	{
		fundo.setPosition(0.f, 0.f);
		fundo.setSize((sf::Vector2f) ger_grafico->getWindowSize());
		fundo.setFillColor(sf::Color::Black);

		if (fonte.loadFromFile("Game/assets/font/SquareGame.otf"))
			printf("Fonte carregada");
		else
			printf("Fonte não carregada");

		AgeOfWarriors.setFont(fonte);
		AgeOfWarriors.setString("Age of Warriors ++");
		AgeOfWarriors.setPosition(150.f, 100.f);
		AgeOfWarriors.setCharacterSize(60);

		Fase1.setFont(fonte);
		Fase1.setString("Fase 1 - Deserto");
		Fase1.setPosition(240.f, 350.f);
		Fase1.setCharacterSize(45);

		Fase2.setFont(fonte);
		Fase2.setString("Fase 1 - Floresta");
		Fase2.setPosition(240.f, 500.f);
		Fase2.setCharacterSize(45);

	}

	Menu::~Menu()
	{
	}

	int Menu::executar()
	{

		ger_grafico->getWindow()->setMouseCursorVisible(true);

		ger_grafico->desenhaElemento(fundo);
		ger_grafico->desenhaElemento(AgeOfWarriors);
		ger_grafico->desenhaElemento(Fase1);
		ger_grafico->desenhaElemento(Fase2);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (sf::Mouse::getPosition().x > Fase1.getGlobalBounds().left - 240 && sf::Mouse::getPosition().x < Fase1.getGlobalBounds().left + Fase1.getGlobalBounds().width -240 &&
				sf::Mouse::getPosition().y > Fase1.getGlobalBounds().top  - 350 && sf::Mouse::getPosition().y < Fase1.getGlobalBounds().top + Fase1.getGlobalBounds().height - 350)
				return 1;

			if (sf::Mouse::getPosition().x > (int)Fase2.getGlobalBounds().left && sf::Mouse::getPosition().x < (int)Fase2.getGlobalBounds().left + Fase2.getGlobalBounds().width &&
				sf::Mouse::getPosition().y > (int)Fase2.getGlobalBounds().top && sf::Mouse::getPosition().y < (int)Fase2.getGlobalBounds().top + Fase2.getGlobalBounds().height)
				return 2;
		}
		return 0;

	}
}