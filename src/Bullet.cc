#include "Bullet.hh"

Bullet::Bullet(const char* textureUrl, int col, int row, float width, float height, float scale, float moveSpeed,
sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world, b2Vec2 direction) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;
  this->direction = direction;
  rigidbody->SetSensor();
}

Bullet::~Bullet()
{
}

void Bullet::Movement()
{
  rigidbody->Move(b2Vec2(direction.x* moveSpeed, direction.y * moveSpeed));
}

void Bullet::Update(float& deltaTime)
{
  GameObject::Update(deltaTime);
  Movement();
}
void Bullet::Draw()
{
  GameObject::Draw();
}
