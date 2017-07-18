#include "CStateCordinator.h"

CStateCordinator::CStateCordinator() : _p_current(0) {}

CStateCordinator::CStateCordinator(const CStateCordinator &sc) {}

void CStateCordinator::push_new_state(CState *st) {
  _v_state.push_back(st);
  if (!_p_current) {
    _p_current = st;
  }
}
void CStateCordinator::push_state_transition(CTransition *tr) {
  _v_transition.push_back(tr);
};

void CStateCordinator::Notified(std::string ev) {

  bool waivered_own_state = _p_current->Notified(ev);
  if (waivered_own_state == true) {
    CState *next = select_out_for_next_state(ev);
    if (next)
      _p_current = next;
  }

  return;
}

bool CStateCordinator::CreateState() { return false; }

bool CStateCordinator::CreateTransition() { return false; };
