#pragma once

/* Código inspirado no vídeo do monitor Giovane Limas Salvi 2022.2 */

namespace Gerenciador
{
	class Grafico
	{
	private:
		static Grafico* pGraf;
		sf::RenderWindow* window;

		Grafico();
	public:
		~Grafico();
		static Grafico* getGrafico();
		sf::RenderWindow* getWindow() { return window; }
		sf::Vector2u getWindowSize() { return window->getSize(); }
		void limpaJanela() { window->clear(); }
		void desenhaElemento(sf::RectangleShape body) { window->draw(body); }
		void desenhaSprite(sf::Sprite sprite) { window->draw(sprite); }
		void mostraElementos() { window->display(); }
		void fecharJanela() { window->close(); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
		sf::Texture textura2;
		sf::Sprite background;
	};

}

