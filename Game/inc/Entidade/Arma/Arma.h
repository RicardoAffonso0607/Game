#pragma once

#include "Entidade/Entidade.h"

class Arma : public Entidade
{
protected:	
	static const bool damageable;// danific�vel?
	static const bool ghost;// atravessa objetos?
	static const bool movable;// � m�vel?

	bool facing_left;

public:
	Arma();
	virtual ~Arma();

	bool getDamageable() const override;// danific�vel?
	bool getGhost() const override;// atravessa objetos?
	bool getMovable() const override;// � m�vel?

	//void move() override;// se move
	//void rotacionar() override;// rotaciona o corpo
	void setDireita() override;// mira pra direita
	void setEsquerda() override;// mira pra esquerda
};