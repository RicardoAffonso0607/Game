#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Arma/Arma.h"

class Jogador : public Personagem
{
protected:
	sf::String player_nickname = sf::String::String();

	static const bool retardable;

	bool attacker = false;
	bool allow_jump = true;
	bool jumped = false;

	float pontuacao = NULL;
	float jump_strength = NULL;

	Arma* pArma = nullptr;

public:
	Jogador();
	virtual ~Jogador();

	bool getJumped() /*override*/;

	void setAttacker(int i) /*override*/;
	void events() /*override*/;
	void setGun(Arma* pArma) /*override*/;

	bool getRetardable() const override;
};
