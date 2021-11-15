#pragma once
#include<SFML/Graphics.hpp>
#include "GameObject.hh"

class Enemy : public GameObject
{
private:
float moveSpeed{};
sf::Vector2f* position{};
int x = 0;
int dx = 1;
public:
    Enemy(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position,sf::RenderWindow*& window, b2World*& world, float moveSpeed);
    ~Enemy();

    void Update(float& deltaTime) override;
    void Draw() override;

    void autoMove( int &x, int &y);
    void FlipSprite();
};

