#pragma once
class Jogo
{
private:
	sf::RenderWindow window;

public:
	Jogo();
	~Jogo();

	void executar();

	void eventos();
	void teclas_pressionadas();
};

