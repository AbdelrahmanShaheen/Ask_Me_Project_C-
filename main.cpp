#include "ask_system.h"
AskSystem* AskSystem::instance = nullptr;

int main()
{
    AskSystem *service;
    service = AskSystem::GetInstance();
    service->run();
    service->FreeInstance();
}
// Note i am using singleton design pattern to provide only one object of AskSystem.
