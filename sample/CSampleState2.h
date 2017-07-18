#ifndef __CSAMPLESTATE2_H__
#define __CSAMPLESTATE2_H__

#include "CState.h"

class CSampleState2 : public CState {
private:
public:
  CSampleState2(std::string name) { _name = name; };
  virtual ~CSampleState2(){};
  bool Notified(std::string ev) {
    if (_worker != nullptr)
      _worker->Action("action2");
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE2_H__ */
