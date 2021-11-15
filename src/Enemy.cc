#include "Enemy.hh"
#include "InputsSystem.hh"
#include "Animation.hh"

Animation* runEnemy{new Animation()};

Enemy::Enemy(const char* textureUrl, int col, int row, float width, float height, float scale,
sf::Vector2f* position,sf::RenderWindow*& window, b2World*& world, float moveSpeed) :
GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world)
{
    this->moveSpeed = moveSpeed;
    this->position = position;
    //this->x = position->x;
    rigidbody->SetRotationFreeze(true);

    runEnemy = new Animation(0, 5, drawable, 0.08f, 2);
}

Enemy::~Enemy()
{
}

void Enemy::Draw(){
    GameObject::Draw();
}

void Enemy::Update(float& deltaTime){
    GameObject::Update(deltaTime);
    autoMove(x, dx);
    runEnemy->Play(deltaTime);
    FlipSprite();
}

void Enemy::autoMove(int &x, int &dx){
    x += dx;
    if(x <= -2000 || x >= 2000){
        dx *= -1;
    }
    
    rigidbody->Move(b2Vec2(dx * moveSpeed, 0));
}

void Enemy::FlipSprite()
{
    drawable->GetSprite()->setScale(dx > 0 ? scale :
    dx < 0 ? -scale :
    drawable->GetSprite()->getScale().x, drawable->GetSprite()->getScale().y);
}
