#include "CState.h"

EventCompare_e CState::event_compare(const std::string ev1,
                                     const std::string ev2) {
  return ev1.compare(ev2) == 0 ? Same_e : Different_e;
};

void CState::PushCondion(const CondionType_e typ, const CCondition *cond) {
  if (typ == CONDTYPE_PRE) {
    _v_pre_condition.push_back(cond);
  } else if (typ == CONDTYPE_POST) {
    _v_post_condition.push_back(cond);
  } else {
    // do nothing
  }
}
