#pragma once

#include "Entidade/Entidade.h"

class Projetil : public Entidade
{
protected:
	static const bool attacker;// causa dano?
	static const bool movable;// é móvel?
	static const bool damageable;// é danificável?
	static const bool ghost;// atravessa objetos?

	static const sf::Vector2f vel;// velocidade

	static const float mass;// massa

	bool facing_left;// mirando pra esquerda?]
	//bool colidiu;// colidiu com alguma coisa?
	int life = 1;

	//Entidade* pColidiu;// ponteiro para o que colidiu
	
public:
	Projetil();
	virtual ~Projetil();

	bool getAttacker() const override;// causa dano?
	bool getMovable() const override;// é móvel?
	bool getDamageable() const override;// é danificável?
	bool getGhost() const override;// atravessa objetos?
	bool getJumped() const override { return false; }

	void move() override;// se move
	void setDireita() override;// vai pra direita
	void setEsquerda() override;// vai pra esquerda

	//void setEntColidiu(Entidade* pauxColidiu) override;
	int getLife() const override;

	void applyDamage(int ent_damage) override;
};