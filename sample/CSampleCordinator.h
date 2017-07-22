#ifndef __CSAMPLECORDINATOR_H__
#define __CSAMPLECORDINATOR_H__

#include "CStateCordinator.h"

const char StateName_1[] = "CSampleState1";
const char StateName_2[] = "CSampleState2";

const char EventName_1[] = "event1";
const char EventName_2[] = "event2";

class CSampleCordinator : public CStateCordinator {
private:
  /* data */
public:
  static const char *EventNameList[];
  CSampleCordinator(){};
  virtual ~CSampleCordinator(){};
  /*! \fn bool CreateState()
   * @brief Factory method for States
   * @detail Factory method for States
   */
  bool CreateState();
  bool CreateTransition();
};

#endif /* end of include guard: __CSAMPLECORDINATOR_H__ */
