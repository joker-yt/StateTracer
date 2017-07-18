#include "CSampleCordinator.h"
#include <iostream>

int main(int argc, char *argv[]) {

  CSampleCordinator cordinator;

  cordinator.CreateState();
  cordinator.CreateTransition();
  std::cout << "start!"
            << "\n";
  std::cout << "now: -> " << cordinator.CurrentState()->Name() << "\n";

  cordinator.Notified(std::string{EventName_1});
  std::cout << "next: ->" << cordinator.CurrentState()->Name() << "\n";

  cordinator.Notified(std::string{EventName_2});
  std::cout << "next: ->" << cordinator.CurrentState()->Name() << "\n";
  return 0;
}
