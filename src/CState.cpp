#include "CState.h"

void CState::create_worker(){};

void CState::PushWorker(CWorker *wk) {
  std::cout << "Don't use this method"
            << "\n";
  _worker = wk;
}
void CState::PushCondion(const CondionType_e typ, const CCondition *cond) {
  if (typ == CONDTYPE_PRE) {
    _v_pre_condition.push_back(cond);
  } else if (typ == CONDTYPE_POST) {
    _v_post_condition.push_back(cond);
  } else {
    // do nothing
  }
}
