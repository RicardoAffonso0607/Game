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
	static const bool damageable;// é danificável?
	static const bool ghost;// é atravessável por objetos?

	bool facing_left;// olhando pra esquerda?
	bool attacker;// pode atacar?
	bool atacou;// atacou recentemente?
	bool colidiu;

	Entidade* pColidiu;

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

	//void events() /*override*/;
};