#include "pch.h"
#include "Entidade/Personagem/Jogador/Jogador.h"

const bool Jogador::retardable = true;

const float Jogador::jump_strength = 150.f;
const float Jogador::gun_pos = .4f;

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
	return jumped;
}

bool Jogador::getRetardable() const
{
	return retardable;
}

void Jogador::setGun(Entidade* gun)
{
	if (pArma)
		delete pArma;
	pArma = dynamic_cast<Arma*>(gun);
}

void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {//Direita
		body.move(sf::Vector2f(vel.x, 0.f));
		facing_left = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {//Esquerda
		body.move(sf::Vector2f(-vel.x, 0.f));
		facing_left = true;
	}
	if (god_mode) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))//Cima
			body.move(sf::Vector2f(0.f, -this->vel.y));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))//Baixo
			body.move(sf::Vector2f(0.f, this->vel.y));
		
	}
	printf("%f %f %d %d %d %d %d\n",jumped_height, jump_strength, colidiu_baixo ? 1 : 0, colidiu_cima ? 1 : 0, allow_jump ? 1 : 0, jumped ? 1 : 0, flying ? 1 : 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumped && allow_jump) {
		colidiu_cima = false;
		colidiu_baixo = false;
		jumped = true;
	}
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
			attack_delay = sf::milliseconds(500);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			attacker = true;
			attack_instant = clock.getElapsedTime();
			attack_delay = sf::milliseconds(55);
			int i=0, cadence = 3;
			do{
				if (clock.getElapsedTime() - attack_instant > attack_delay){
					pArma->attack();
					i++;
					attack_instant = clock.getElapsedTime();
				}
			} while (i <= cadence);
			attack_instant = clock.getElapsedTime();
			attack_delay = sf::milliseconds(1500);
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