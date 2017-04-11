#include <iostream>
#include "CState.h"
#include "CSampleState.h"
#include "CSampleState2.h"
#include "CStateCordinator.h"
#include "CStateCordinatorDebug.h"
#include "CTransition.h"
#include "CAction.h"
#include "CWorker.h"

class CAction1 : public CAction {
private:
public:
  CAction1(){};
  virtual ~CAction1(){};
  void Action() {
    std::cout << "this is action1"
              << "\n";
  }
};

class CAction2 : public CAction {
private:
public:
  CAction2(){};
  virtual ~CAction2(){};
  void Action() {
    std::cout << "this is action2"
              << "\n";
  }
};

void transition(CStateCordinator *ch) {
  CTransition *tr;
  tr = new CTransition("pattern1", "CSampleState", "CSampleState2", "event1");
  ch->PushStateTransition(tr);

  tr = new CTransition("pattern2", "CSampleState2", "CSampleState", "event2");
  ch->PushStateTransition(tr);
}

int main(int argc, char *argv[]) {
  CWorker *wk = new CWorker();
  CAction *act = new CAction1();
  wk->PushAction("action1", act);
  act = new CAction2();
  wk->PushAction("action2", act);

  CStateCordinator *ch = new CStateCordinatorDebug();
  CState *st;
  st = new CSampleState();
  st->PushWorker(wk);
  ch->PushNewState(st);

  st = new CSampleState2();
  st->PushWorker(wk);
  ch->PushNewState(st);
  ch->Debug();

  transition(ch);

  std::cout << "start!"
            << "\n";
  std::cout << "now: -> " << ch->CurrentState()->Name() << "\n";

  ch->Notified("event1");
  std::cout << "next: ->" << ch->CurrentState()->Name() << "\n";
  ch->Notified("event2");
  std::cout << "next: ->" << ch->CurrentState()->Name() << "\n";

  return 0;
}
