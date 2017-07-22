#ifndef __CEVENTBRANCH_H__
#define __CEVENTBRANCH_H__

#include <string>

class CEventBranch {
private:
protected:
  std::string _ev_name;

public:
  CEventBranch(std::string ev) : _ev_name(ev){};
  virtual ~CEventBranch(){};
};

#endif /* end of include guard: __CEVENTBRANCH_H__ */
