#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

const float Jogador::jump_strength = 450.f;
const float Jogador::gun_pos = .8f;

Jogador::Jogador(sf::Vector2f aux_vel_max) :
	attacker(false),
	pontuacao(0),
	player_nickname(" "),
	pArma(nullptr),
	retardable(true),
	vel_max(aux_vel_max)
{

}

Jogador::~Jogador()
{
}

//void Jogador::setAttacker(int gun_type, int attack_type)
//{
//	if (!attack_delay) {
//		if (attack_type == ATQ_LONGO) {
//			attacker = true;
//			attack_delay = gun->getDelay();
//			attack_instant = clock.getElapsedTime();
//		}
//		else if (attack_type == ATQ_CURTO) {
//			attacker = true;
//			attack_delay = 2*gun->getDelay();
//			attack_instant = clock.getElapsedTime();
//		}
//	}
//}



bool Jogador::getRetardable() const
{
	return retardable;
}

void Jogador::setGun(Entidade* gun)
{
	//if (pArma)
	//	delete pArma;
	pArma = dynamic_cast<Arma*>(gun);
}

Entidade* Jogador::getArma() const
{
	return pArma;
}

void Jogador::executar()
{
	flying = true;
	if (colidiu && pColidiu && !pColidiu->getMovable())
	{
		if (retardable && pColidiu->getRetardant()) {
			
			vel = vel_max - sf::Vector2f(pColidiu->getSlowness()*vel_max.x, 0.f);
			retardable = false;
		}
		if (pColidiu->getAttacker())
			life -= pColidiu->getDamage();
		pColidiu = nullptr;
		colidiu = false;
	}
	else {
		retardable = true;
		vel = vel_max;
	}
	sf::Listener::setPosition(sf::Vector3f(body.getPosition().x, 0.f, body.getPosition().y));
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumped && allow_jump) {
	//	colidiu_cima = false;
	//	colidiu_baixo = false;
	//	jumped = true;
	//}
	//if (jumped && !colidiu_cima && jumped_height < jump_strength)
	//{
	//	body.move(sf::Vector2f(0.f, -vel.y));
	//	jumped_height += vel.y - getMass()*ACEL_GRAV;
	//}
	//if (jumped && !flying)
	//{
	//	jumped = false;
	//	jumped_height = 0.f;
	//}
	if (atacou)
		attacker = false;
	if (clock.getElapsedTime() - attack_delay > attack_instant) {
		attack_delay = sf::Time::Zero;
		atacou = false;
	}
	if (facing_left) {
		pArma->setEsquerda();
		pArma->setEntPos(body.getPosition()+sf::Vector2f(- pArma->getEntSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
	}
	else {
		pArma->setDireita();
		pArma->setEntPos(body.getPosition() + sf::Vector2f(body.getSize().x, gun_pos * body.getSize().y - pArma->getEntSize().y));
	}
	pArma->resetRot();
	attack();
}

void Jogador::attack_single()
{
	if (attack_delay <= sf::Time::Zero) {
		attacker = true;
		pArma->attack();
		attack_instant = clock.getElapsedTime();
		attack_delay = normal_delay;
	}
}

void Jogador::attack_burst()
{
	if (attack_delay <= sf::Time::Zero) {
		attacker = true;
		attack_instant = clock.getElapsedTime();
		attack_delay = cadence_delay;
		int i = 0;
		do {
			if (clock.getElapsedTime() - attack_instant > attack_delay) {
				pArma->attack();
				i++;
				pArma->changePos(sf::Vector2f(0.f, -30.f));
				attack_instant = clock.getElapsedTime();
			}
		} while (i <= cadence);
		attack_instant = clock.getElapsedTime();
		attack_delay = burst_delay;
	}
}

float Jogador::getJumpStrength() const
{
	return jump_strength;
}

bool Jogador::getGodMode() const
{
	return god_mode;
}