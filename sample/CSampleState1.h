#ifndef __CSAMPLESTATE1_H__
#define __CSAMPLESTATE1_H__

#include "CState.h"
#include "CSampleWorker.h"

class CSampleState1 : public CState {
private:
protected:
  void create_worker() { _worker = new CSampleWorker(); };

public:
  CSampleState1(std::string name) : CState(name) { create_worker(); };
  virtual ~CSampleState1(){};
  bool Notified(std::string ev) {
    if (_worker != nullptr)
      _worker->Do(std::string{ActionName_1});
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE1_H__ */
