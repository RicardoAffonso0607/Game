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
		int getWindowHeight() { return window->getSize().y; }
		void limpaJanela() { window->clear(); }
		void desenhaElemento(sf::RectangleShape body) { window->draw(body); }
		void mostraElementos() { window->display(); }
		void fecharJanela() { window->close(); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
	};

}

