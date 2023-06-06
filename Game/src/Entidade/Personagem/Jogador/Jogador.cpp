#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

const bool Jogador::retardable = true;

const float Jogador::jump_strength = 450.f;
const float Jogador::gun_pos = .8f;

Jogador::Jogador() :
	attacker(false),
	pontuacao(0),
	player_nickname(" "),
	pArma(nullptr)
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

bool Jogador::getJumped() const
{ 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	else
		return false;
}

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

void Jogador::move()
{
	sf::Listener::setPosition(sf::Vector3f(body.getPosition().x, 0.f, body.getPosition().y));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//Direita
		body.move(vel.x, 0.f);
		facing_left = false;
		sf::Listener::setDirection(1.f, 0.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Esquerda
		body.move(-vel.x, 0.f);
		facing_left = true;
		sf::Listener::setDirection(1.f, 0.f, 0.f);
	}
	if (god_mode) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
			body.move(0.f, -this->vel.y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
			body.move(0.f, this->vel.y);
		
	}
	//printf("%f %f %d %d %d %d %d\n",jumped_height, jump_strength, colidiu_baixo ? 1 : 0, colidiu_cima ? 1 : 0, allow_jump ? 1 : 0, jumped ? 1 : 0, flying ? 1 : 0);
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
	attack();
}

void Jogador::attack()
{
	if (attack_delay <= sf::Time::Zero) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			attacker = true;
			pArma->attack();
			attack_instant = clock.getElapsedTime();
			attack_delay = normal_delay;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			attacker = true;
			attack_instant = clock.getElapsedTime();
			attack_delay = cadence_delay;
			int i=0;
			do{
				if (clock.getElapsedTime() - attack_instant > attack_delay){
					pArma->attack();
					i++;
					attack_instant = clock.getElapsedTime();
				}
			} while (i <= cadence);
			attack_instant = clock.getElapsedTime();
			attack_delay = burst_delay;
		}
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