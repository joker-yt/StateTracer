#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "CCondition.h"
#include "CWorker.h"
#include <iostream>
#include <string>
#include <vector>

/**
* @brief    Object about the Status
* @details  CStatus. This class has some CAction classes (shows \n
            a behavior), and defines an action how an application \n
            should behave when received each event. \n\n

            The classes in an application should be created by \n
            inherriting CState class.
* @image    html "../image/CCondition_PrePostAction.png"
* @section  Initialization
* @image    html "../image/CState_Initial.png"
* @cond
* @startuml CState_Initial.png
*
* Create CState
* main -> CState: new
* CState --> main:

* Create CWorker
* main -> CWorker: new
* CWorker --> main: worker_obj

* Create CAction
* main -> CAction: new
* CAction --> main: action_obj
*
* main -> CWorker: PushAction(action_obj)
* CWorker --> main:

* main -> CState:PushWorker(worker_obj)
* CState --> main:
* note left : Ready to action

* @enduml
* @endcond
*/
class CState {
private:
protected:
  std::string _name;
  CWorker *_worker;
  std::vector<const CCondition *> _v_pre_condition;
  std::vector<const CCondition *> _v_post_condition;

  void action(std::string action) { _worker->Do(action); };
  void decide_to_do(std::string ev){};

  virtual void create_worker();

public:
  CState(){};
  CState(std::string name) {
    _name = name;
    create_worker();
  };
  CState(const CState &obj) = default;
  virtual ~CState(){};
  std::string &Name() { return _name; }
  void PushWorker(CWorker *wk);
  void PushCondion(const CondionType_e typ, const CCondition *cond);
  virtual bool Notified(std::string ev) { return false; };
};

#endif /* end of include guard: __CSTATE_H__ */
