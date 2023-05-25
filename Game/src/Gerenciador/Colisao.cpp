#include "pch.h"
#include "Gerenciador/Colisao.h"

namespace Gerenciador{
    Colisao::Colisao(){}

    Colisao::~Colisao(){}

    /* Verifica se a colisão entre as entidades é possível */
    void Colisao::collided(ListaEntidades* list_ent){
        int i, j;
        for (i = 0; i < list_ent->getSize(); i++) {
            if (list_ent->getEntity(i)->isMovable())
                for (j = i; j < list_ent->getSize(); j++)
                    if(list_ent->getEntity(i) != list_ent->getEntity(j))
                        collide(list_ent->getEntity(i), list_ent->getEntity(j));
        }
    }

    /* A colisão ocorre quando entre centros a distância x é menor que soma das
       larguras/2 e a distância y é menor que soma das alturas/2 */
    void Colisao::collide(Entidade* ent1, Entidade* ent2){
        sf::Vector2f cg1, cg2, centerDistance, centerSum, sobre;
        cg1 = ent1->getPosition() + 0.5f*ent1->getEntSize();
        cg2 = ent2->getPosition() + 0.5f*ent2->getEntSize();
        centerDistance.x = fabs(cg2.x - cg1.x);
        centerDistance.y = fabs(cg2.y - cg1.y);
        centerSum.x = 0.5f*(ent2->getEntSize().x + ent1->getEntSize().x);
        centerSum.y = 0.5f*(ent2->getEntSize().y + ent1->getEntSize().y);
        sobre = centerSum - centerDistance;
        if((sobre.x>0 && sobre.y>0)||(sobre.x>0 && !centerDistance.y)||(sobre.y>0 && !centerDistance.x)) {// colidiu
            effects(ent1, ent2);// aplica dano e lentidão
            ricochet(ent1, ent2, sobre);// volta a posição sem sobreposição
        }
    }

    /* Vértices do retângulo */
    struct Colisao::vertex{
        sf::Vector2f ul, ur, bl, br;
    };

    /* Encontra os vértices do retângulo */
    void Colisao::vertexMath(vertex *rect, Entidade *ent){
        rect->ul = ent->getPosition();// up left
        rect->ur = rect->ul + sf::Vector2f(ent->getEntSize().x, 0);// up right
        rect->bl = rect->ul + sf::Vector2f(0,ent->getEntSize().y);// bottom left
        rect->br = rect->bl + sf::Vector2f(ent->getEntSize().x, 0);// bottom right
    }

    /* Ao andar e sobrepor um fixo, volta à posição só encostado, e se for um móvel, empurra */
    void Colisao::ricochet(Entidade* ent1, Entidade* ent2, sf::Vector2f sobre) {
        vertex e1, e2;
        vertexMath(&e1, ent1);
        vertexMath(&e2, ent2);
        if (ent1->isMovable() && !ent2->isMovable()) {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.0f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.0f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.0f, sobre.y));
                else//direita cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(sobre.x, 0.0f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.0f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.0f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.0f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-sobre.x, 0.0f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x)//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.0f, -sobre.y));
            else//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.0f, sobre.y));
        }
        else if (!ent1->isMovable() && ent2->isMovable()){
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y)//direita entre vértices
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.0f));
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y)//cima canto direito
                    ent2->changePosition(sf::Vector2f(0.0f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y)//baixo canto direito
                    ent2->changePosition(sf::Vector2f(0.0f, sobre.y));
                else//direita cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(sobre.x, 0.0f));
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x) {
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y)//esquerda entre vértices
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.0f));
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y)//cima canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.0f, -sobre.y));
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y)//baixo canto esquerdo
                    ent2->changePosition(sf::Vector2f(0.0f, sobre.y));
                else//esquerda cantos superior e inferior
                    ent2->changePosition(sf::Vector2f(-sobre.x, 0.0f));
            }
            else if (e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x)//cima entre vértices
                ent2->changePosition(sf::Vector2f(0.0f, -sobre.y));
            else//baixo entre vértices
                ent2->changePosition(sf::Vector2f(0.0f, sobre.y));
        }
        else {
            if (e1.ul.x < e2.ur.x && e1.ur.x > e2.ur.x) {
                if (e1.ul.y <= e2.ur.y && e1.bl.y >= e2.br.y){//direita entre vértices
                    ent1->changePosition(sf::Vector2f(0.5f*sobre.x, 0.0f));
                    ent2->changePosition(sf::Vector2f(-0.5f*sobre.x, 0.0f));
                }
                else if (sobre.x >= sobre.y && e1.ul.y < e2.ur.y){//cima canto direito
                    ent1->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
                }
                else if (sobre.x >= sobre.y && e1.bl.y > e2.br.y){//baixo canto direito
                    ent1->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
                }
                else{//direita cantos superior e inferior
                    printf("entrou\n");
                    ent1->changePosition(sf::Vector2f(0.5f*sobre.x, 0.0f));
                    ent2->changePosition(sf::Vector2f(-0.5f*sobre.x, 0.0f));
                }
            }
            else if (e1.ur.x > e2.ul.x && e1.ul.x < e2.ul.x){
                if (e1.ur.y <= e2.ul.y && e1.br.y >= e2.bl.y){//esquerda entre vértices
                    ent1->changePosition(sf::Vector2f(-0.5f*sobre.x, 0.0f));
                    ent2->changePosition(sf::Vector2f(0.5f*sobre.x, 0.0f));
                }
                else if (sobre.x >= sobre.y && e1.ur.y < e2.ul.y){//cima canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
                }
                else if (sobre.x >= sobre.y && e1.br.y > e2.bl.y){//baixo canto esquerdo
                    ent1->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
                    ent2->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
                }
                else{//esquerda cantos superior e inferior
                    ent1->changePosition(sf::Vector2f(-0.5f*sobre.x, 0.0f));
                    ent2->changePosition(sf::Vector2f(0.5f*sobre.x, 0.0f));
                }
            }
            else if(e1.bl.y > e2.ul.y && e1.ul.y < e2.ul.y && e1.bl.x >= e2.ul.x && e1.br.x <= e2.ur.x){//cima entre vértices
                ent1->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
            }
            else{//baixo entre vértices
                ent1->changePosition(sf::Vector2f(0.0f, 0.5f*sobre.y));
                ent2->changePosition(sf::Vector2f(0.0f, -0.5f*sobre.y));
            }
        }

    }

    /* Efeitos causados pela colisão */
    void Colisao::effects(Entidade* ent1, Entidade* ent2){
        if(ent1->isDamageable() && ent2->isAttacker()){
            
        }

        if(ent1->isAttacker() && ent2->isDamageable()){
            
        }

        if(ent1->isMovable() && ent2->isRetarder()){
            
        }

        if(ent1->isRetarder() && ent2->isMovable()){
            
        }

    }

    /* Aceleração da gravidade */
    void Colisao::gravity(Entidade* ent1, Entidade* ent2){
        
    }

    /* Pulo */
    void Colisao::jump(Entidade* ent){}

    /* Funcionamento de um projétil */
    void Colisao::trajectory(Entidade* ent) {

    }
}