#pragma once

#include "stdafx.h"

class CollisionManager{
  private:
    List::EntityList* playerList;
    List::ObstacleList* obstacleList;
  public:
    CollisionManager(List::EntityList* Player, List::ObstacleList* obstacleList);
    ~CollisionManager();
    const sf::Vector2f collisionMath(Entity::Entity* player1);
    void Execute();
};
