#ifndef __CSAMPLESTATE1_H__
#define __CSAMPLESTATE1_H__

#include "CState.h"

class CSampleState1 : public CState {
private:
public:
  CSampleState1(std::string name) { _name = name; };
  virtual ~CSampleState1(){};
  bool Notified(std::string ev) {
    if (_worker != nullptr)
      _worker->Action("action1");
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE1_H__ */
