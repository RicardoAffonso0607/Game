#pragma once

#include "Entidade/Jogador/Personagem.h"
#include "Entidade/Arma/Arma.h"

inline constexpr int ATQ_LONGO = 1;
inline constexpr int ATQ_CURTO = 2;

class Jogador : public Personagem
{
private:
	sf::String player_nickname;

	static const int atq_longo;
	static const int atq_curto;

	const bool movable;
	const bool damageable;

	bool attacker;
	bool allow_jump = true;
	bool jumped = false;

	float pontuacao;
	float jump_strength;

	Arma* pArma;

public:
	Jogador();
	virtual ~Jogador();

	bool getJumped() override;

	void setAttacker(int i) override;
	void events() override;
	void setGun(Arma* pArma) override;
};