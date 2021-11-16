#pragma once
#include<box2d/box2d.h>
#include"Enemy.hh"

class ContactEventManager : public b2ContactListener
{
private:
 std::vector<Enemy*> enemies;
 b2World* world;
  
public:
  ContactEventManager();
  ~ContactEventManager();
  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;
  void setWolrd(b2World*& wolrd);
};

