#ifndef __CSAMPLESTATE2_H__
#define __CSAMPLESTATE2_H__

#include "CState.h"
#include "CEventBranch.h"

class CSampleState2 : public CState {
private:
protected:
  void create_worker();
  void teach_action_to_worker();

public:
  CSampleState2(std::string name) : CState(name){};
  virtual ~CSampleState2(){};
  void Ready();
  bool Notified(std::string ev);
};

#endif /* end of include guard: __CSAMPLESTATE2_H__ */
