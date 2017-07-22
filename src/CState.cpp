#include "CState.h"
void CState::NewEventBranch(CEventBranch eb) { _v_event_branch.push_back(eb); };

void CState::PushCondion(const CondionType_e typ, const CCondition *cond) {
  if (typ == CONDTYPE_PRE) {
    _v_pre_condition.push_back(cond);
  } else if (typ == CONDTYPE_POST) {
    _v_post_condition.push_back(cond);
  } else {
    // do nothing
  }
}
