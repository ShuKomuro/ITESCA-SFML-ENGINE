#include "Character.hh"
#include "InputsSystem.hh"
#include "Animation.hh"
#include <stack>
#include <iostream>
#include "Bullet.hh"

Animation* idleAnimation{new Animation()};
Animation* runAnimation{new Animation()};

Character::Character(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world, std::vector<GameObject*>*& gameObjects) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;
  this->gameObjects = gameObjects;
  gameObjects->push_back(this);
  this->position = position;
  lastAxis = sf::Vector2f(-1.0f, 0.0f);
  CreateBullet();

  rigidbody->SetRotationFreeze(true);

  idleAnimation = new Animation(0, 5, drawable, 0.05f, 5);
  runAnimation = new Animation(0, 5, drawable, 0.08f, 6);
}

Character::~Character()
{
}

void Character::Draw()
{
  GameObject::Draw();

}

void Character::Update(float& deltaTime)
{
  GameObject::Update(deltaTime);
  FlipSprite();
  Move();

  if(std::abs(InputsSystem::GetAxis().x) || std::abs(InputsSystem::GetAxis().y))
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }
  if(InputsSystem::GetAxis().x != 0.f || InputsSystem::GetAxis().y != 0.f)
  {
    lastAxis = InputsSystem::GetAxis();
  }
  if(InputsSystem::isPressed())
  {
    if(isShooting==false){
      isShooting = true;
      // std::cout << "create bullets" << std::endl;
      CreateBullet();
    }
  }
  else
  {
    //std::cout << "not create bullets" << std::endl;
    isShooting = false;
  }
}

void Character::FlipSprite()
{
    drawable->GetSprite()->setScale(InputsSystem::GetAxis().x > 0 ? scale :
    InputsSystem::GetAxis().x < 0 ? -scale :
    drawable->GetSprite()->getScale().x, drawable->GetSprite()->getScale().y);
}

void Character::Move()
{
  rigidbody->Move(b2Vec2(InputsSystem::GetAxis().x * moveSpeed, InputsSystem::GetAxis().y * moveSpeed));
}


sf::Sprite* Character::GetSprite() const
{
  return drawable->GetSprite();
}

void Character::CreateBullet()
{
  std::cout << "X: " << GetPosition().x << "Y :" << GetPosition().y << std::endl;
  std::cout << "world: " << world << std::endl;
  std::cout << "window: " << window << std::endl;
  std::cout << "----------------------------------------------------------------" << std::endl;
  Bullet* bullet{new Bullet("assets/BulletSprites.png", 0, 12, 8.f, 8.f, 4.f, 500.f, new sf::Vector2f(GetPosition()),
  window, world, b2Vec2(lastAxis.x, lastAxis.y))};
  bullet->SetTagName("Bullet");
  gameObjects->push_back(bullet);
}
