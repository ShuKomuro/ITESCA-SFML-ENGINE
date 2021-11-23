#include "Game.hh"
#include "constance.hh"
#include "Collider.hh"
#include "Character.hh"
#include<iostream>
#include "TileGroup.hh"
#include "InputsSystem.hh"
#include "Enemy.hh"
#include "Wall.hh"

Collider* collider{new Collider(100, 100, 100, 100, sf::Color::Green, 5.f)};

sf::Clock* timer{new sf::Clock()};
float deltaTime{};

Character* character1{};
GameObject* chest1{};
GameObject* chest2{};
Wall* wall1{};
GameObject* wall2{};
GameObject* wall3{};
GameObject* wall4{};
Enemy* enemy1{};
DrawMap* walls{};
DrawMap* floorT{};
sf::Vector2f lastPos{};
sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f)); 
bool isAlive = true;


TileGroup* tileGroup{};

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), G_NAME);
  event = new sf::Event();

  //gravity = new b2Vec2(0.f, 9.8f);
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  
  gameObjects = new std::vector<GameObject*>();
  deleteList = new std::vector<GameObject*>();

  contactEventManager = new ContactEventManager(deleteList);


  character1 = new Character("assets/sprites.png", 0, 5, 16.f, 16.f, 
  playerScale, playerSpeed, new sf::Vector2f(400, 300), window, world, gameObjects);
  character1->SetTagName("Player");
  
  lastPos = character1->GetPosition();
  
  chest1 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(350, 350), b2BodyType::b2_staticBody, window, world);
  chest1->SetTagName("chest");

  chest2 = new GameObject("assets/sprites.png", 6, 1, 16, 16, playerScale,
  new sf::Vector2f(448, 448), b2BodyType::b2_dynamicBody, window, world);
  chest2->SetTagName("dynamic chest");

  enemy1 = new Enemy( "assets/sprites.png", 0, 2, 16, 16, playerScale,
  new sf::Vector2f(600, 500), window, world, enemySpeed);
  enemy1->SetTagName("Enemy");

  wall1 = new Wall("", 0, 0, 10.f, 600.f, playerScale, 
  new sf::Vector2f(0, 0), b2BodyType::b2_staticBody, window, world, true);
  wall1->SetTagName("Wall");

  wall2 = new Wall("", 0, 0, 10.f, 600.f, playerScale, 
  new sf::Vector2f(416, 0), b2BodyType::b2_staticBody, window, world, true);
  wall2->SetTagName("Wall");

  wall3 = new Wall("", 0, 0, 832.f, 10.f, playerScale, 
  new sf::Vector2f(0, 0), b2BodyType::b2_staticBody, window, world, true);
  wall3->SetTagName("Wall");

  wall4 = new Wall("", 0, 0, 832.f, 10.f, playerScale, 
  new sf::Vector2f(0, 300), b2BodyType::b2_staticBody, window, world, true);
  wall4->SetTagName("Wall");

  //tileGroup = new TileGroup(window, 10, 10, "assets/tile.png", "assets/maps/map1.tg", 16, 16, 4.f);

  walls = new DrawMap("assets/tilemap.png", window, 39, 27, sf::Vector2u(16, 16), wallsTiles);
  floorT = new DrawMap("assets/tilemap.png", window, 39, 27, sf::Vector2u(16, 16), floorTiles);

  //gameObjects->push_back(character1);
  gameObjects->push_back(chest1);
  gameObjects->push_back(chest2);
  gameObjects->push_back(enemy1);
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
   window->draw(*collider->GetShape());
  for(auto& gameObject : *gameObjects)
  {
    gameObject->Draw();
  }
  world->DebugDraw();
}

void Game::Render()
{
  for(auto& gameObject : *deleteList)
  {
    gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameObject), gameObjects->end());
    delete gameObject;
  }
  deleteList->clear();

  window->clear(sf::Color(0, 0, 0, 255));
  Draw();
  window->display();
}
void Game::Init()
{
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(b2Draw::e_shapeBit);
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
    //std::cout << "X: " << sf::Mouse::getPosition(*window).x << "Y: " << sf::Mouse::getPosition(*window).y << std::endl;
    deltaTime = timer->getElapsedTime().asSeconds();
    timer->restart();

    UpdatePhysics();
    for(auto& gameObject : *gameObjects){
      if(gameObject->GetTagName()=="Player"){
        isAlive = true;
        break;
      }else{
        isAlive = false;
      }
    }
    for(auto& gameObject : *gameObjects)
    {      
      gameObject->Update(deltaTime);
    }
    window->setView(view);
    if(isAlive){
      lastPos = character1->GetPosition();
    }
    view.setCenter(lastPos);
    Render();
  }

  delete window;
  delete event;
}