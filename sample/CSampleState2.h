#ifndef __CSAMPLESTATE2_H__
#define __CSAMPLESTATE2_H__

#include "CState.h"

class CSampleState2 : public CState {
private:
public:
  CSampleState2() { _name = "CSampleState2"; };
  virtual ~CSampleState2(){};
  bool Notified(std::string ev) {
    _worker->Action("action2");
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE2_H__ */
