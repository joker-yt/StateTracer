#include "CSampleCordinator.h"
#include "CSampleState1.h"
#include "CSampleState2.h"

const char *CSampleCordinator::EventNameList[] = {EventName_Initial,
                                                  EventName_1, EventName_2};

bool CSampleCordinator::CreateState() {
  _p_ctx = new IContext();

  CState *st;
  st = new CState(std::string{StateName_Initial}, _p_ctx);
  push_new_state(st);

  st = new CSampleState1(std::string{StateName_1}, _p_ctx);
  push_new_state(st);

  st = new CSampleState2(std::string{StateName_2}, _p_ctx);
  push_new_state(st);
  Debug();

  return true;
}

bool CSampleCordinator::CreateTransition() {
  CTransition *tr;
  tr =
      new CTransition("pattern0", std::string{StateName_Initial},
                      std::string{StateName_1}, std::string{EventName_Initial});
  push_state_transition(tr);

  tr = new CTransition("pattern1", std::string{StateName_1},
                       std::string{StateName_2}, std::string{EventName_1});
  push_state_transition(tr);

  tr = new CTransition("pattern2", std::string{StateName_2},
                       std::string{StateName_1}, std::string{EventName_2});
  push_state_transition(tr);

  return true;
}
