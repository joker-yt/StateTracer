#include "CSampleState1.h"
#include "CWorker.h"

const char ActionName_1[] = "action1";

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
//###################################################
void CSampleState1::create_worker() { _worker = new CWorker(); }
void CSampleState1::teach_action_to_worker() {
  _worker->LearnAction(std::string{ActionName_1}, new CAction1{});
}

void CSampleState1::Ready() {
  create_worker();
  teach_action_to_worker();
};

bool CSampleState1::Notified(std::string ev) {
  if (_worker != nullptr)
    _worker->Do(std::string{ActionName_1});
  return true;
};
