#include "CStateCordinator.h"

CStateCordinator::CStateCordinator(IHandler *phndl)
    : _p_current(nullptr), _p_ctx(nullptr), _p_hndl(phndl) {}

CStateCordinator::CStateCordinator(const CStateCordinator &sc) {}

void CStateCordinator::push_new_state(CState *st) { _v_state.push_back(st); }
void CStateCordinator::push_state_transition(CTransition *tr) {
  _v_transition.push_back(tr);
};

CState *CStateCordinator::select_out_next_state(std::string ev) {
  for (auto iter = _v_transition.begin(); iter != _v_transition.end(); ++iter) {
    if (_p_current->Name() == (*iter)->SrcStateName() &&
        (*iter)->EventName() == ev) {
      return state((*iter)->DstStateName());
    }
  }
  return nullptr;
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
