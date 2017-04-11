#ifndef __CSTATECORDINATOR_H__
#define __CSTATECORDINATOR_H__

#include <vector>
#include "CState.h"
#include "CTransition.h"
#include <assert.h>

class CStateCordinator {
private:
protected:
  std::vector<CState *> _v_state;
  std::vector<CTransition *> _v_transition;
  CState *_p_current;

  CState *state(std::string name) {
    for (auto iter = _v_state.begin(); iter != _v_state.end(); ++iter) {
      if (name == (*iter)->Name()) {
        return (*iter);
      }
    }

    return 0;
  };

  CState *select_out_for_next_state(std::string ev) {
    for (auto iter = _v_transition.begin(); iter != _v_transition.end();
         ++iter) {
      if (_p_current->Name() == (*iter)->SrcStateName() &&
          (*iter)->EventName() == ev) {
        return state((*iter)->DstStateName());
      }
    }
  }

public:
  CStateCordinator() : _p_current(0){};
  virtual ~CStateCordinator(){};

  void PushNewState(CState *st) {
    _v_state.push_back(st);
    if (!_p_current) {
      _p_current = st;
    }
  }
  void PushStateTransition(CTransition *tr) { _v_transition.push_back(tr); };
  void PushStateTransitionWithCondition(std::string src, std::string dest,
                                        std::string event, CCondition &cond) {
    assert(1);
  };

  virtual void Notified(std::string ev) {

    bool waivered_own_state = _p_current->Notified(ev);
    if (waivered_own_state == true) {
      CState *next = select_out_for_next_state(ev);
      if (next)
        _p_current = next;
    }

    return;
  }
  CState *CurrentState() { return _p_current; };
  CState *NextState(std::string name) { return state(name); }
  void Debug() {
    for (auto iter = _v_state.begin(); iter != _v_state.end(); ++iter) {
      std::cout << "Debug: " << (*iter)->Name() << "\n";
    }
  }
};

#endif /* end of include guard: __CSTATECORDINATOR_H__ */
