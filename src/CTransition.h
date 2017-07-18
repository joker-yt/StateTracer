#ifndef __CTRANSITION_H__
#define __CTRANSITION_H__

#include "CCondition.h"
#include <string>

class CTransition {
private:
protected:
  std::string _name;
  std::string _src_state;
  std::string _dst_state;
  std::string _ev;
  CCondition *_cond;

public:
  CTransition(std::string name, std::string src_st, std::string dst_st,
              std::string ev, CCondition *cond = 0) {
    _name = name;
    _src_state = src_st;
    _dst_state = dst_st;
    _ev = ev;
    _cond = cond;
  };
  virtual ~CTransition(){};
  const std::string Name() const { return _name; };
  const std::string SrcStateName() const { return _src_state; };
  const std::string DstStateName() const { return _dst_state; };
  const std::string EventName() const { return _ev; };
  CCondition *Condition() const { return _cond; };
};

#endif /* end of include guard: __CTRANSITION_H__ */
