#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DrawPhysics.hh"
#include "GameObject.hh"
#include "DrawMap.hh"
#include "ContactEventManager.hh"
#include "Enemy.hh"

class Game
{
private:
    sf::RenderWindow *window{};
    sf::Event *event{};
    b2Vec2 *gravity{};
    b2World *world{};
    b2Draw *drawPhysics{};
    ContactEventManager* contactEventManager{};
    std::vector<GameObject *> *gameObjects;
    std::vector<GameObject *> *deleteList;
    //std::vector<Enemy *> *enemies;

public:
    Game();
    ~Game();

    void Draw();
    void Render();
    void Init();
    void Update();
    void Inputs();
    void UpdatePhysics();
};
