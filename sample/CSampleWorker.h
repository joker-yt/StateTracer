#ifndef __CSAMPLEWORKER_H__
#define __CSAMPLEWORKER_H__

#include "CWorker.h"
#include "CAction.h"

const char ActionName_1[] = "action1";
const char ActionName_2[] = "action2";

class CAction1 : public CAction {
private:
public:
  CAction1(){};
  virtual ~CAction1(){};
  void Action() {
    std::cout << "this is action1"
              << "\n";
  }
};

class CAction2 : public CAction {
private:
public:
  CAction2(){};
  virtual ~CAction2(){};
  void Action() {
    std::cout << "this is action2"
              << "\n";
  }
};

class CSampleWorker : public CWorker {
private:
  void create_action() {
    _action_map[std::string{ActionName_1}] = new CAction1();
    _action_map[std::string{ActionName_2}] = new CAction2();
  }

public:
  CSampleWorker() { create_action(); };
  virtual ~CSampleWorker(){};
};

#endif /* end of include guard: __CSAMPLEWORKER_H__ */
