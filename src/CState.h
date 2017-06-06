#ifndef __CState
#define __CState

#include "CWorker.h"
#include <string>
#include <iostream>

/**
* @brief CState
* @image html "../image/CState.png"
* @cond
* @startuml CState.png
*
* Foo -> Server: Request
* Server --> Foo: Response
*
* @enduml
* @endcond
*/
class CState {
private:
protected:
  std::string _name;
  CWorker *_worker;

  void action(std::string action) { _worker->Action(action); };
  void decide_to_do(std::string ev){};

public:
  CState(){};
  virtual ~CState(){};
  std::string &Name() { return _name; }
  void PushWorker(CWorker *wk) { _worker = wk; }
  virtual bool Notified(std::string ev){};
};

#endif /* end of include guard: __CState */
