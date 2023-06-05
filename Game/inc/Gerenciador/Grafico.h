#pragma once

/* C�digo inspirado no v�deo do monitor Giovane Limas Salvi 2022.2 */

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
		sf::Vector2f getWindowSize() { return (sf::Vector2f) window->getSize(); }
		sf::View* getCamera() { return camera; }
		void limpaJanela() { window->clear(); }
		void desenhaElemento(sf::RectangleShape body) { window->draw(body); }
		void desenhaSprite(sf::Sprite sprite) { window->draw(sprite); }
		void mostraElementos() { window->display(); }
		void fecharJanela() { window->close(); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
		void setCamera() { window->setView(*camera); }
		sf::Texture textura2;
		sf::Sprite background;
	};

}

