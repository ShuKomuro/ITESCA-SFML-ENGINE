#include "Game.hh"
#include "constance.hh"
#include "Collider.hh"
#include "Character.hh"
//#include "GameObject.hh"
//#include"Boxes.hh"
#include"DrawMap.hh"
#include<iostream>

Collider* collider{new Collider(100, 100, 100, 100, sf::Color::Green, 5.f)};

sf::Clock* timer{new sf::Clock()};
float deltaTime{};
const float playerSpeed{200.f};
const float playerScale{4.f};
const float boxScale{2.f};


Character* character1{};
GameObject* chest1{};
GameObject* chest2{};
DrawMap* walls{};
DrawMap* floorT{};
//Boxes* caja{};


Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), G_NAME);
  event = new sf::Event();

  //gravity = new b2Vec2(0.f, 9.8f);
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>;

  character1 = new Character("assets/sprites.png", 0, 5, 16.f, 16.f, 
  playerScale, playerSpeed, new sf::Vector2f(100, 100), window, world);
  
  chest1 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(288, 288), b2BodyType::b2_staticBody, window, world);

  chest2 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(500, 600), b2BodyType::b2_dynamicBody, window, world);

  walls = new DrawMap("assets/tilemap.png", window, 13, 9, sf::Vector2u(16, 16), wallsTiles);
  floorT = new DrawMap("assets/tilemap.png", window, 13, 9, sf::Vector2u(16, 16), floorTiles);

  gameObjects->push_back(character1);
  gameObjects->push_back(chest1);
  gameObjects->push_back(chest2);
  //caja = new Boxes("assets/sprites.png", 6, 1, 16.f, 16.f, 
  //playerScale, new sf::Vector2f(500, 500), window, world);
}

Game::~Game()
{
}

void Game::Inputs()
{

}

void Game::Draw()
{
   window->draw(*floorT);
   window->draw(*walls);
  for(auto& gameObject : *gameObjects)
  {
    gameObject->Draw();
  }
  world->DebugDraw();
}

void Game::Render()
{
  window->clear(sf::Color(0, 0, 0, 255));
  Draw();
  window->display();
}
void Game::Init()
{
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(b2Draw::e_shapeBit);

  Update();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
  //std::cout << deltaTime << std::endl;
}

void Game::Update()
{
  while (window->isOpen())
  {
    while (window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }
    deltaTime = timer->getElapsedTime().asSeconds();
    timer->restart();

    UpdatePhysics();

    Inputs();

    for(auto& gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

    Render();
  }

  delete window;
  delete event;
}




