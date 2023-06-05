#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	sf::Vector2f vel;// velocidade atual

	sf::Time attack_instant;// instante que ocorreu ataque

	sf::Clock clock;// tempo de jogo

	sf::Time attack_delay;// cooldown entre ataques

	int life;// vida atual

	static const bool movable;// se move?
	static const bool damageable;// � danific�vel?
	static const bool ghost;// � atravess�vel por objetos?
	
	bool jumped;// pulou?
	bool facing_left;// olhando pra esquerda?
	bool attacker;// pode atacar?
	bool atacou;// atacou recentemente?

public:
	Personagem();
	virtual ~Personagem();

	bool getMovable() const override;// se move?
	bool getAttacker() const override;// est� apto a atacar?
	bool getDamageable() const override;// � danific�vel?
	bool getFacingLeft() const override;// est� olhando pra esquerda?
	bool getGhost() const override;// pode ser atravessado por objetos?
	bool getJumped() const override;// pulou?

	int getLife() const override;// qual a vida atual?

	sf::Vector2f getVel() const override;// qual a velocidade atual?

	void applyDamage(int ent_damage) override;// aplicar dano na vida
	void applySlowness(float ent_slowness) override;// aplicar retardo na velocidade
	void setAtacou() override;// informa que atacou recentemente
	void setDireita() override;// olhar pra direita
	void setEsquerda() override;// olhar pra esquerda

	bool allow_jump;
	bool colidiu_baixo;
	bool colidiu_cima;
	bool flying;

	float jumped_height;

	//void events() /*override*/;
};