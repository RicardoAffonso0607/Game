#pragma once

#include "Entidade/Entidade.h"

class Arma : public Entidade
{
protected:	
	static const bool damageable;// danificável?
	static const bool ghost;// atravessa objetos?
	static const bool movable;// é móvel?
	static const bool retardant;// é retardante?

	bool facing_left;
	float mass = .1f;
	
	Entidade* pColidiu;
	bool colidiu = false;

public:
	Arma();
	virtual ~Arma();

	bool getDamageable() const override;// danificável?
	bool getGhost() const override;// atravessa objetos?
	bool getMovable() const override;// é móvel?

	void setDireita() override;// mira pra direita
	void setEsquerda() override;// mira pra esquerda

	void move() override;

	float getMass() const override { return mass; }

	void setEntColidiu(Entidade* pauxColidiu) override;

	void setColidiu() override;

	bool getRetardant() const override;

	
};