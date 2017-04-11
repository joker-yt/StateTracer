#ifndef __CSAMPLESTATE_H__
#define __CSAMPLESTATE_H__

#include "CState.h"

class CSampleState : public CState {
private:
public:
  CSampleState() { _name = "CSampleState"; };
  virtual ~CSampleState(){};
  bool Notified(std::string ev) {
    _worker->Action("action1");
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE_H__ */
