#pragma once

#include "Entidade/Entidade.h"

class Arma : public Entidade
{
protected:	
	static const bool damageable;// danificável?
	static const bool ghost;// atravessa objetos?
	static const bool movable;// é móvel?

	bool facing_left;

public:
	Arma();
	virtual ~Arma();

	bool getDamageable() const override;// danificável?
	bool getGhost() const override;// atravessa objetos?
	bool getMovable() const override;// é móvel?

	//void move() override;// se move
	//void rotacionar() override;// rotaciona o corpo
	void setDireita() override;// mira pra direita
	void setEsquerda() override;// mira pra esquerda
};