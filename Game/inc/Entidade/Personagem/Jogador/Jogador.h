#pragma once

#include "Entidade/Personagem/Personagem.h"

class Jogador : public Personagem
{
protected:
	sf::String player_nickname;// apelido do jogador

	static const bool retardable;// sua velocidade pode ser reduzida?

	static const float jump_strength;// altura m�xima de pulo

	bool attacker;// est� apto a atacar?

	int pontuacao;// pontua��o do jogador

	Entidade* pArma;// arma que est� segurando

public:
	Jogador();
	virtual ~Jogador();

	bool getJumped() const override;// est� pulando?

	bool getRetardable() const override;// sua velocidade pode ser reduzida?

	float getJumpStrength() const override;// altura m�xima de pulo?

	void move() override;// a��es de movimento
	void attack() override;// a��es de ataque
	void setAttacker(int i) /*override*/;
	void events() /*override*/;
	void setGun(Entidade* pArma) override;// pega uma arma
};
