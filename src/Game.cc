#include "Game.hh"
#include "constance.hh"
#include "Collider.hh"
#include "Character.hh"
#include<iostream>
#include "TileGroup.hh"
#include "InputsSystem.hh"
#include "Enemy.hh"

Collider* collider{new Collider(100, 100, 100, 100, sf::Color::Green, 5.f)};

sf::Clock* timer{new sf::Clock()};
float deltaTime{};

Character* character1{};
GameObject* chest1{};
GameObject* chest2{};
Enemy* enemy1{};
DrawMap* walls{};
DrawMap* floorT{};
sf::View* view; 

TileGroup* tileGroup{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), G_NAME);
  event = new sf::Event();


  //gravity = new b2Vec2(0.f, 9.8f);
  view = new sf::View(sf::FloatRect(0.f, 0.f, (float)WINDOW_WIDTH, (float) WINDOW_HEIGHT));
  
  //view->reset(sf::FloatRect(0.f,0.f, (float)WINDOW_WIDTH);
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  enemies = new std::vector<Enemy*>;
  contactEventManager = new ContactEventManager();
  
  gameObjects = new std::vector<GameObject*>;
  

  character1 = new Character("assets/sprites.png", 0, 5, 16.f, 16.f, 
  playerScale, playerSpeed, new sf::Vector2f(100, 100), window, world);

  character1->SetTagName("Player");

  view->setCenter(character1->GetPosition());
  
  chest1 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(350, 350), b2BodyType::b2_staticBody, window, world);
  chest1->SetTagName("chest");

  chest2 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(448, 448), b2BodyType::b2_dynamicBody, window, world);
  chest2->SetTagName("dynamic chest");

  enemy1 = new Enemy( "assets/sprites.png", 0, 2, 16, 16, playerScale,
  new sf::Vector2f(600, 500), window, world, enemySpeed);
  enemy1->SetTagName("Enemy");

  //tileGroup = new TileGroup(window, 10, 10, "assets/tile.png", "assets/maps/map1.tg", 16, 16, 4.f);

  walls = new DrawMap("assets/tilemap.png", window, 13, 9, sf::Vector2u(16, 16), wallsTiles);
  floorT = new DrawMap("assets/tilemap.png", window, 13, 9, sf::Vector2u(16, 16), floorTiles);

  gameObjects->push_back(character1);
  gameObjects->push_back(chest1);
  gameObjects->push_back(chest2);
  enemies->push_back(enemy1);

}

Game::~Game()
{
}

void Game::Inputs()
{

}

void Game::Draw()
{
   //tileGroup->Draw();
   window->draw(*floorT);
   window->draw(*walls);

  for(auto& gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  for(auto& enemys : *enemies)
  {
    enemys->Draw();
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
  contactEventManager->setWolrd(world);
  world->SetContactListener(contactEventManager);
  
  Update();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
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
    
    for(auto& gameObject : *gameObjects)
    {
      gameObject->Update(deltaTime);
    }

    for(auto& enemys : *enemies)
    {
      enemys->Update(deltaTime);
    }

    Render();
  }

  delete window;
  delete event;
}




