#include "CSampleCordinator.h"
#include "IHandler.h"
#include <iostream>

int main(int argc, char *argv[]) {
  IHandler *phndl = new IHandler{};
  CSampleCordinator cordinator{phndl};

  cordinator.CreateState();
  cordinator.CreateTransition();

  cordinator.Ready();
  std::cout << "start!"
            << "\n";
  std::cout << "now: -> " << cordinator.CurrentState()->Name() << "\n";

  cordinator.Notified(std::string{EventName_1});
  std::cout << "next: ->" << cordinator.CurrentState()->Name() << "\n";

  cordinator.Notified(std::string{EventName_2});
  std::cout << "next: ->" << cordinator.CurrentState()->Name() << "\n";
  return 0;
}
