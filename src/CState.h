#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "CCondition.h"
#include "CWorker.h"
#include "IContext.h"
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
#include "CEventBranch.h"

enum EventCompare_e { Different_e = 0, Same_e };

class CState {
private:
protected:
  std::string _name;
  CWorker *_worker;
  IContext *_p_ctx;
  std::vector<CEventBranch> _v_event_branch;
  std::vector<const CCondition *> _v_pre_condition;
  std::vector<const CCondition *> _v_post_condition;

  void action(std::string action) { _worker->Do(action); };
  void decide_to_do(std::string ev){};

  EventCompare_e event_compare(const std::string ev1, const std::string ev2);

  virtual void create_worker(){};
  virtual void teach_action_to_worker(){};

public:
  CState(){};
  CState(std::string name, IContext *pctx) {
    _name = name;
    _p_ctx = pctx;
  };
  CState(const CState &obj) = default;
  virtual ~CState(){};
  virtual void Ready(){};
  std::string &Name() { return _name; }
  void PushCondion(const CondionType_e typ, const CCondition *cond);
  virtual bool Notified(std::string ev) { return true; };
};

#endif /* end of include guard: __CSTATE_H__ */
