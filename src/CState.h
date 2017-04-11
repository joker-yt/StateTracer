#ifndef __CState
#define __CState

#include "CWorker.h"
#include <string>
#include <iostream>

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
