#pragma once

/* Código inspirado no vídeo do monitor Giovane Limas Salvi 2022.2 */

namespace Gerenciador
{
	class Grafico
	{
	private:
		static Grafico* pGraf;
		sf::RenderWindow* window;
		sf::View* camera;

		Grafico();
	public:

		~Grafico();
		static Grafico* getGrafico();
		sf::RenderWindow* getWindow() { return window; }
		sf::Vector2u getWindowSize() { return window->getSize(); }
		sf::View* getCamera() { return camera; }
		void limpaJanela() { window->clear(); }
		void desenhaElemento(sf::RectangleShape body) { window->draw(body); }
		void desenhaElemento(sf::Text texto) { window->draw(texto); }
		void desenhaSprite(sf::Sprite sprite) { window->draw(sprite); }
		void mostraElementos() { window->display(); }
		void fecharJanela() { window->close(); }
		void setCamera() { window->setView(*camera); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
	};

}

