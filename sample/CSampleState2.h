#ifndef __CSAMPLESTATE2_H__
#define __CSAMPLESTATE2_H__

#include "CState.h"
#include "CSampleWorker.h"

class CSampleState2 : public CState {
private:
protected:
  void create_worker() { _worker = new CSampleWorker(); };

public:
  CSampleState2(std::string name) : CState(name) { create_worker(); };
  virtual ~CSampleState2(){};
  bool Notified(std::string ev) {
    if (_worker != nullptr)
      _worker->Do(std::string{ActionName_2});
    return true;
  };
};

#endif /* end of include guard: __CSAMPLESTATE2_H__ */
