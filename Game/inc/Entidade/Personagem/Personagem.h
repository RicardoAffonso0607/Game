#pragma once

#include "Entidade/Entidade.h"

class Personagem : public Entidade
{
protected:
	sf::Vector2f vel;// velocidade atual

	sf::Time attack_instant;// instante que ocorreu ataque

	sf::Clock clock;// tempo de jogo

	sf::Time attack_delay;// cooldown entre ataques

	sf::Time relogio_zero;

	int life;// vida atual

	static const bool movable;// se move?
	static const bool damageable;// é danificável?
	static const bool ghost;// é atravessável por objetos?

	bool facing_left;// olhando pra esquerda?
	bool attacker;// pode atacar?
	bool atacou;// atacou recentemente?
	bool colidiu;

	Entidade* pColidiu;

	float jump_strength = false;
	float jumped_height = false;
	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool allow_jump = false;
	bool jumped = false;
	bool flying = false;

public:
	Personagem();
	virtual ~Personagem();

	bool getMovable() const override;// se move?
	bool getAttacker() const override;// está apto a atacar?
	bool getDamageable() const override;// é danificável?
	bool getFacingLeft() const override;// está olhando pra esquerda?
	bool getGhost() const override;// pode ser atravessado por objetos?
	bool getJumped() const override;// pulou?

	int getLife() const override;// qual a vida atual?

	sf::Vector2f getVel() const override;// qual a velocidade atual?

	void applyDamage(int ent_damage) override;// aplicar dano na vida
	void applySlowness(float ent_slowness) override;// aplicar retardo na velocidade
	void setAtacou() override;// informa que atacou recentemente
	void setDireita() override;// olhar pra direita
	void setEsquerda() override;// olhar pra esquerda
	void setEntColidiu(Entidade* pauxColidiu) override;// ponteiro se encostou em cima de algo não inerte
	void setColidiu() override;// encostou em cima de algo não inerte
	void setClockZero(sf::Time aux_tempo) override;


	void setJumpedHeight(float height) { jumped_height = height; }
	void setColidiuBaixo() { colidiu_baixo = true; }
	void unsetColidiuBaixo() { colidiu_baixo = false; }
	void setColidiuCima() { colidiu_baixo = true; }
	void unsetColidiuCima() { colidiu_baixo = false; }
	void unsetJumped() { jumped = false; }
	void setFlying() { flying = true; }
	void unsetFlying() { flying = false; }
	void setAllowJump() { allow_jump = true; }
	void unsetAllowJump() { allow_jump = false; }
	float getJumpedHeight() { return jumped_height; }
	bool getColidiuBaixo() { return colidiu_baixo; }
	bool getColidiuCima() { return colidiu_cima; }
	bool getFlying() { return flying; }
	//void events() /*override*/;

	sf::Time getClock() override;
};