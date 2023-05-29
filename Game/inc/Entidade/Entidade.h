#pragma once

#include "Ente.h"
#include "Gerenciador/Grafico.h"

class Entidade : public Ente
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape body;
	static Gerenciador::Grafico* pGerGraf;

	bool movable;
	bool attacker;
	bool retarder;
	bool damageable;
	bool jumped = false;
	bool colidiu = false;
	unsigned int attack_delay;
	unsigned int retarder_delay;
	unsigned int retarder_timer;

public:
	Entidade(int id);
	~Entidade();

	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf) { pGerGraf = pauxGerGraf; }
	void draw() { pGerGraf->desenhaElemento(body); }

	virtual void move() = 0;
	virtual void attack() = 0;

	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getEntSize() { return body.getSize(); }
	void changePosition(sf::Vector2f dif_pos) { body.move(dif_pos); }
	bool isMovable() { return movable; }
	bool isAttacker() { return attacker; }
	bool isRetarder() { return retarder; }
	bool isDamageable() { return damageable; }
	bool isJumped() { return jumped; }
	float getJumpedHeight() { return jumped_height; }
	float jumped_height = 0.f;
};

