#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "DrawPhysics.hh"
#include "GameObject.hh"
#include "DrawMap.hh"
#include "ContactEventManager.hh"

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
