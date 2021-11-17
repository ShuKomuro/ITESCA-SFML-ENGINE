#pragma once

#include<SFML/Graphics.hpp>
#include "GameObject.hh"
//#include<vector>

class Wall : public GameObject
{
private:
public:
    Wall(const char* textureUrl, int col, int row, float width, float height, float scale,
  sf::Vector2f* position, b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world, bool isWall);
    ~Wall();

    void Update(float& deltaTime) override;
    void Draw() override;
    //void isWall() override;
};

