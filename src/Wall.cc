#include "Wall.hh"

Wall::Wall(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world, bool isWall):
  GameObject(textureUrl, col, row, width, height, scale, position, b2BodyType::b2_dynamicBody, window, world, isWall)
{
    
}

Wall::~Wall()
{
}

void Wall::Draw()
{

}

void Wall::Update(float& deltaTime)
{
}
