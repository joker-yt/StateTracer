#include "CStateCordinator.h"

CStateCordinator::CStateCordinator() : _p_current(0) {}

CStateCordinator::CStateCordinator(const CStateCordinator &sc) {}

void CStateCordinator::push_new_state(CState *st) { _v_state.push_back(st); }
void CStateCordinator::push_state_transition(CTransition *tr) {
  _v_transition.push_back(tr);
};

void CStateCordinator::Notified(std::string ev) {

  bool waivered_own_state = _p_current->Notified(ev);
  if (waivered_own_state == true) {
    CState *next = select_out_next_state(ev);
    if (next)
      _p_current = next;
  }

  return;
}

bool CStateCordinator::CreateState() { return false; }

bool CStateCordinator::CreateTransition() { return false; };

void CStateCordinator::Ready() {
  std::string init_state_name{StateName_Initial};
  for (CState *p : _v_state) {
    p->Ready();

    if (p->Name() == init_state_name)
      _p_current = p;
  }

  this->Notified(std::string{EventName_Initial});
};
