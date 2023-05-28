#pragma once

/* Código inspirado no vídeo do monitor Giovane Limas Salvi 2022.2 */

<<<<<<< HEAD
namespace Gerenciador
=======
namespace Gerenciador 
>>>>>>> main
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
<<<<<<< HEAD
		void mostraElementos() { window->display(); }
=======
		void mostraElemntos() { window->display(); }
>>>>>>> main
		void fecharJanela() { window->close(); }
		const bool verificaJanelaAberta() { return (window->isOpen()) ? true : false; }
	};

}

