#include "ContactEventManager.hh"
#include<iostream>
#include<string>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& deleteList)
{
  this->deleteList = deleteList;
}

ContactEventManager::~ContactEventManager()
{
}

void ContactEventManager::BeginContact(b2Contact *contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  std::string a = actorA->GetTagName();
  std::string b = actorB->GetTagName();

  if(actorA && actorB )
  {
    if(!(a == "Player" && b == "Bullet")){
      std::cout << "c " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
      std::cout << "collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    }

    if(a == "Player" && b == "Enemy"){
      std::cout << "c " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
      std::cout << "* c muere * xd" << std::endl;
    }

    if(a == "Enemy" && b == "Bullet"){
      std::cout << "c " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
      std::cout << "* LE DA LA BALA * xd" << std::endl;
      //enemies.erase(&actorA);
      //world->DestroyBody(contact->GetFixtureA()->GetBody());
      deleteList->push_back(actorB);
      
    }
    
  }
}
void ContactEventManager::EndContact(b2Contact *contact)
{

}

/*void ContactEventManager::setWolrd(b2World*& wolrd){
  this->world = world;
}*/