#ifndef __CWORKER_H__
#define __CWORKER_H__

#include "CAction.h"
#include <unordered_map>
#include <string>

class CWorker {
private:
protected:
  std::string _name;
  std::unordered_map<std::string, CAction *> _action_map;

public:
  CWorker(){};
  virtual ~CWorker(){};
  std::string &Name() { return _name; };
  void LearnAction(std::string act_name, CAction *action) {
    _action_map[act_name] = action;
  };
  virtual void Do(std::string action) { _action_map[action]->Action(); };
};

#endif /* end of include guard: __CWORKER_H__ */
