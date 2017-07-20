#ifndef __CSAMPLESTATE1_H__
#define __CSAMPLESTATE1_H__

#include "CState.h"
#include "CWorker.h"

class CSampleState1 : public CState {
private:
protected:
  void create_worker();
  void teach_action_to_worker();

public:
  CSampleState1(std::string name) : CState(name){};
  virtual ~CSampleState1(){};
  void Ready();
  bool Notified(std::string ev);
};

#endif /* end of include guard: __CSAMPLESTATE1_H__ */
