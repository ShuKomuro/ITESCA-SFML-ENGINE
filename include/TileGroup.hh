#pragma once
#include<iostream>
#include "Tile.hh"

class TileGroup
{
private:
  std::vector<Tile*>* tiles;
  sf::RenderWindow* window{};
public:
  TileGroup(sf::RenderWindow*& window);
  ~TileGroup();
  void Draw();
  void GenerateGroup();
};