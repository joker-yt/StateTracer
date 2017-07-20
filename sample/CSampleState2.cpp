#include "CSampleState2.h"
#include "CWorker.h"

const char ActionName_2[] = "action2";

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
//###################################################
void CSampleState2::create_worker() { _worker = new CWorker(); }
void CSampleState2::teach_action_to_worker() {
  _worker->LearnAction(std::string{ActionName_2}, new CAction2{});
}

void CSampleState2::Ready() {
  create_worker();
  teach_action_to_worker();
};

bool CSampleState2::Notified(std::string ev) {
  if (_worker != nullptr)
    _worker->Do(std::string{ActionName_2});
  return true;
};
