#ifndef __CSTATECORDINATOR_H__
#define __CSTATECORDINATOR_H__

#include "CState.h"
#include "CTransition.h"
#include "IContext.h"
#include "IHandler.h"
#include <assert.h>

/**
* @brief    Main behavior of the states
* @details  CStateCordinator. This class has some CState classes, \n
            and the one of them behaves the "current status". \n
            This class also behaves as a "Abstract Factory" pattern. \n\n

            If CStateCordinator receives a event, \n
            it notifies the event to "current class". \n
            "Current class" will action along the event (if inmplemented \n
            as it does) \n\n

            The rules which one state to another state in a state, \n
            are memorized into CTransition classes, and the CTransition classes
            are pushed into CStateCordinator class .
* @section  Initialization
            1. main function creates some CState classes, and one
            CStateCordinator.
            2. it pushes created CState classes into CStateCordinator.
            3. main function creates some CTransition classes.
            4. it pushes created CTransition classes into CStateCordinator.
* @image    html "../image/CStateCordinator_Initial.png"
* @cond
* @startuml CStateCordinator_Initial.png

* Create CStateCordinator
* main -> CStateCordinator: new
* CStateCordinator --> main

* Create CState1
* main -> CState1: new
* CState1 --> main: state_obj1

* Create CState2
* main -> CState2: new
* CState2 --> main: state_obj2
*
* main -> CStateCordinator:PushNewState(state_obj1)
* main -> CStateCordinator:PushNewState(state_obj2)

* Create CTransition1
* main -> CTransition1: new(src_state1, dst_state1, event1)
* CTransition1 --> main: trans_obj1

* Create CTransition2
* main -> CTransition2: new(src_state2, dst_state2, event2)
* CTransition2 --> main: trans_obj1

* main -> CStateCordinator: PushStateTransition(trans_obj1)
* main -> CStateCordinator: PushStateTransition(trans_obj2)
* @enduml
* @endcond
*
* @section  Event
*           By Receiving a event, CStateCordinator launch action of
            "current state".
* @image    html "../image/CStateCordinator_event.png"
* @cond
* @startuml CStateCordinator_event.png
* main -> CStateCordinator:Notified(event1)
* CStateCordinator -> CState:Notified(event1)
* CState -> CState:action
* CState --> CStateCordinator:waivered_own_state = true
* CStateCordinator -> CStateCordinator:Next State as "current state"
* CStateCordinator --> main:
* @enduml
* @endcond
*/

const char StateName_Initial[] = "InitialState";

const char EventName_Initial[] = "InitialEvent";

class CStateCordinator {
private:
protected:
  std::vector<CState *> _v_state;
  std::vector<CTransition *> _v_transition;
  CState *_p_current;
  IContext *_p_ctx;
  IHandler *_p_hndl;

  CState *state(std::string name) {
    for (auto iter = _v_state.begin(); iter != _v_state.end(); ++iter) {
      if (name == (*iter)->Name()) {
        return (*iter);
      }
    }

    return 0;
  };

  CState *select_out_next_state(std::string ev);

  void push_new_state(CState *st);
  void push_state_transition(CTransition *tr);

public:
  CStateCordinator(IHandler *phndl);
  CStateCordinator(const CStateCordinator &sc);
  virtual ~CStateCordinator(){};

  CState *CurrentState() { return _p_current; };
  CState *NextState(std::string name) { return state(name); }
  virtual bool CreateState();
  virtual bool CreateTransition();
  void Ready();
  void Notified(std::string ev);

  void Debug() {
    for (auto iter = _v_state.begin(); iter != _v_state.end(); ++iter) {
      std::cout << "Debug: " << (*iter)->Name() << "\n";
    }
  }
};
#endif /* end of include guard: __CSTATECORDINATOR_H__ */
