#include "CSampleCordinator.h"
#include "CAction.h"
#include "CSampleState1.h"
#include "CSampleState2.h"

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

bool CSampleCordinator::CreateState() {
  CWorker *wk = new CWorker();
  CAction *act = new CAction1();
  wk->PushAction("action1", act);
  act = new CAction2();
  wk->PushAction("action2", act);

  CState *st;
  st = new CSampleState1(std::string{StateName_1});
  st->PushWorker(wk);
  push_new_state(st);

  st = new CSampleState2(std::string{StateName_2});
  st->PushWorker(wk);
  push_new_state(st);
  Debug();

  return true;
}

bool CSampleCordinator::CreateTransition() {
  CTransition *tr;
  tr = new CTransition("pattern1", std::string{StateName_1},
                       std::string{StateName_2}, std::string{EventName_1});
  push_state_transition(tr);

  tr = new CTransition("pattern2", std::string{StateName_2},
                       std::string{StateName_1}, std::string{EventName_2});
  push_state_transition(tr);

  return true;
}
