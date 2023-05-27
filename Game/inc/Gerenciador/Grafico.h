#pragma once

/* C�digo inspirado no v�deo do monitor Giovane Limas Salvi 2022.2 */

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
		void limpaJanela() { window->clear(); }
		void desenhaElemento(sf::RectangleShape body) { window->draw(body); }
		void mostraElemntos() { window->display(); }
		void fecharJanela() { window->close(); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
	};

}

