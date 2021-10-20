#include "TileGroup.hh"

TileGroup::TileGroup(sf::RenderWindow*& window)
{
  this->window = window;
  tiles = new std::vector<Tile*>();
  GenerateGroup();
}

TileGroup::~TileGroup()
{

}

void TileGroup::GenerateGroup()
{
  tiles->push_back(new Tile("assets/tile.png", 0, 2, 16.f, 16.f, 4.f, new sf::Vector2f(0, 0)));
  tiles->push_back(new Tile("assets/tile.png", 1, 2, 16.f, 16.f, 4.f, new sf::Vector2f(16*1, 16*2)));
  tiles->push_back(new Tile("assets/tile.png", 2, 2, 16.f, 16.f, 4.f, new sf::Vector2f(16*2, 0)));
}

void TileGroup::Draw()
{
  for(auto& tile : *tiles)
  {
    window->draw(*tile->GetSprite());
  }
}