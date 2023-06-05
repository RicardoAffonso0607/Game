#pragma once

#include "Entidade/Entidade.h"
#include "Entidade/Personagem/Personagem.h"

class Arma : public Entidade
{
protected:
	Personagem* pPersonagem;

	bool attacker = false;
	
	static const bool damageable = false;
	static const bool ghost = false;
	static const bool movable = true;
	static const bool retardant = false;

	bool facing_left;

public:
	Arma();
	virtual ~Arma();

	bool getAttacker() /*override*/;
	void setAttacker() /*override*/;

	bool getMovable() const override;
	bool getAttacker() const override;
	bool getRetardant() const override;
	bool getDamageable() const override;
	bool getGhost() const override;

	void setEsquerda() override;
	void setDireita() override;
};