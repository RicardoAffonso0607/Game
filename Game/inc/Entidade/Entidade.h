
#pragma once

#include "Ente.h"
#include "Gerenciador/Grafico.h"

class Entidade : public Ente
{
protected:
	static Gerenciador::Grafico* pGerGraf;

	sf::RectangleShape body;// corpo do objeto

	sf::Texture textura;// textura do corpo

	float jump_strength = false;
	float jumped_height = false;
	bool colidiu_baixo = false;
	bool colidiu_cima = false;
	bool allow_jump = false;
	bool jumped = false;
	bool flying = false;
	bool colidiu = false;

public:
	Entidade();
	virtual ~Entidade();

	sf::Vector2f getPos() const;// posição do vértice superior esquerdo do objeto na tela
	sf::Vector2f getEntSize() const;// tamanho do objeto na tela

	void setEntPos(sf::Vector2f pos);// define posição do objeto x e y
	void changePos(sf::Vector2f dif_pos);// move o objeto dx e dy
	void draw();// desenha na tela

	/* estáticos */
	static void setGerGraf(Gerenciador::Grafico* pauxGerGraf);
	
	/* virtuais puros */
	virtual bool getMovable() const = 0;// é móvel?
	virtual bool getAttacker() const = 0;// está causando dano?
	virtual bool getDamageable() const = 0;// pode receber dano?
	virtual bool getGhost() const = 0;// pode ser atravessado por outros objetos?

	/* virtuais simples */
	virtual bool getRetardant() const;// está retardando?
	virtual bool getRetardable() const;// é retardável?
	virtual bool getJumped() const;// pulou?
	virtual bool getFacingLeft() const;// está olhando pra esquerda?

	virtual float getMass() const;// qual a massa?
	virtual float getSlowness() const;// porcentagem que diminui a velocidade ao retardar?
	virtual float getJumpStrength() const;// altura máxima do pulo?

	virtual int getDamage() const;// dano que causa?
	virtual int getLife() const;// vida restante atual?

	virtual sf::Vector2f getVel() const;// velocidade atual?

	virtual void move();// ações de movimento
	virtual void attack();// ações de ataque
	virtual void applyDamage(int ent_damage);// aplica o dano na vida
	virtual void applySlowness(float ent_slowness);// aplica o retardo na velocidade
	virtual void setAtacou();// informa que atacou alguém
	virtual void setDireita();// faz olhar para a direita
	virtual void setEsquerda();// faz olhar para a esquerda
	virtual void setGun(Entidade* gun);// pega uma arma
	virtual void setEntColidiu(Entidade* pauxColidiu);
	virtual void setColidiu();

	void setJumpedHeight(float height) { jumped_height = height; }
	void setColidiuBaixo() { colidiu_baixo = true; }
	void unsetColidiuBaixo() { colidiu_baixo = false; }
	void setColidiuCima() { colidiu_baixo = true; }
	void unsetColidiuCima() { colidiu_baixo = false; }
	void unsetJumped() { jumped = false; }
	void setFlying() { flying = true; }
	void unsetFlying() { flying = false; }
	void setAllowJump() { allow_jump = true; }
	void unsetAllowJump() { allow_jump = false; }
	float getJumpedHeight() { return jumped_height; }
	bool getColidiuBaixo() { return colidiu_baixo; }
	bool getColidiuCima() { return colidiu_cima; }
	bool getFlying() { return flying; }
};