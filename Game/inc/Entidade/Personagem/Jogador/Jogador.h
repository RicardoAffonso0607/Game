#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Arma/Arma.h"

class Jogador : public Personagem
{
protected:
	sf::String player_nickname;// apelido do jogador

	static const bool retardable;// sua velocidade pode ser reduzida?

	static const float jump_strength;// altura máxima de pulo

	bool attacker;// está apto a atacar?

	int pontuacao;// pontuação do jogador

	static const float gun_pos;// posição de empunhamento da arma

	Arma* pArma;// arma equipada

public:
	Jogador();
	virtual ~Jogador();

	bool getJumped() const override;// está pulando?

	bool getRetardable() const override;// sua velocidade pode ser reduzida?

	float getJumpStrength() const override;// altura máxima de pulo?

	void move() override;// ações de movimento
	void attack() override;// ações de ataque
	void setAttacker(int i) /*override*/;
	void events() /*override*/;
	void setGun(Entidade* gun) override;// equipa uma arma
};