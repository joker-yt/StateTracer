#ifndef __CCONDITION_H__
#define __CCONDITION_H__

#include <string>

class CCondition {
private:
protected:
public:
  CCondition(){};
  virtual ~CCondition(){};
  virtual bool IsValid() { return false; };
};

#endif /* end of include guard: __CCONDITION_H__ */
