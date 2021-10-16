#pragma once

#include<SFML/Graphics.hpp>
#include "Rigidbody.hh"



class Boxes
{
private:
    sf::Texture* texture{};
    sf::Sprite* sprite{};
    Rigidbody* rigidbody{};
    sf::RenderWindow* window{};
    b2World* world{};
    float scale{};

public:
    Boxes(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, sf::RenderWindow*& window, b2World*& world);
    ~Boxes();

    void Draw();
    void Update(float& deltaTime);
};


