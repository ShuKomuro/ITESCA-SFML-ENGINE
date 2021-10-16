#include "Boxes.hh"
#include "Animation.hh"

Animation* boxAnimation{new Animation()};

Boxes::Boxes(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world)
{
    this->window = window;
    this->world = world;
    this->scale = scale;

    texture = new sf::Texture();
    sprite = new sf::Sprite();

    texture->loadFromFile("assets/sprites.png");
    texture->setSmooth(false);

    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(col * width, row * height, width, height));
    sprite->setColor(sf::Color::White);
    sprite->setPosition(*position);
    sprite->setScale(scale, scale);
    

    rigidbody = new Rigidbody(world, b2BodyType::b2_dynamicBody, 
    new b2Vec2(sprite->getPosition().x, sprite->getPosition().y), 
    width * scale / 2, height * scale / 2, 1, 0, 0, 
    b2Vec2(sprite->getOrigin().x , sprite->getOrigin().y), 0.f);

    sprite->setOrigin(width / 2, height / 2);

    boxAnimation = new Animation(6, 12, sprite, 0.05f, row);
}

Boxes::~Boxes()
{
  
}

void Boxes::Draw()
{
  window->draw(*sprite);

}

void Boxes::Update(float& deltaTime)
{
    sprite->setPosition(rigidbody->GetPositionSFML());
    boxAnimation->Play(deltaTime);
    rigidbody->GetBody()->SetAngularVelocity(0.f);
}