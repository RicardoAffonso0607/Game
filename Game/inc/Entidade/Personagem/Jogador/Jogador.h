#pragma once

#include "Entidade/Personagem/Personagem.h"
#include "Entidade/Arma/Arma.h"

class Jogador : public Personagem
{
protected:
	sf::String player_nickname;// apelido do jogador

	bool retardable;// sua velocidade pode ser reduzida?

	static const float jump_strength;// altura máxima de pulo

	bool attacker;// está apto a atacar?

	int pontuacao;// pontuação do jogador

	static const float gun_pos;// posição de empunhamento da arma

	Arma* pArma;// arma equipada

	bool god_mode = false;// cheat imune a ataques e gravidade

	int cadence = 3;// cadência do ataque múltiplo

	sf::Time cadence_delay = sf::milliseconds(55);// espera entre tiros múltiplos
	sf::Time burst_delay = sf::milliseconds(1500);// espera entre rajadas
	sf::Time normal_delay = sf::milliseconds(500);// espera normal entre disparos

	sf::Vector2f vel_max;

public:
	Jogador(sf::Vector2f aux_vel_max);
	virtual ~Jogador();

	bool getJumped() const override;// está pulando?

	bool getRetardable() const override;// sua velocidade pode ser reduzida?

	float getJumpStrength() const override;// altura máxima de pulo?

	void move() override;// ações de movimento
	void attack() override;// ações de ataque
	void setAttacker(int i) /*override*/;
	void events() /*override*/;
	void setGun(Entidade* gun) override;// equipa uma arma
	bool getGodMode() const override;
	Entidade* getArma() const override;
};