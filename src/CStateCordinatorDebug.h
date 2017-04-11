#ifndef __CSTATECORDINATORDEBUG_H__
#define __CSTATECORDINATORDEBUG_H__

#include <fstream>
class CStateCordinatorDebug : public CStateCordinator {
private:
  std::ofstream _ofs;

public:
  CStateCordinatorDebug() { _ofs.open("debug.txt", std::ios::out); };
  virtual ~CStateCordinatorDebug(){};
  void Notified(std::string ev) {
    _ofs << _p_current->Name() << " --> ";
    CStateCordinator::Notified(ev);
    _ofs << _p_current->Name() << " : " << ev;
    _ofs.close();
  }
};

#endif /* end of include guard: __CSTATECORDINATORDEBUG_H__ */
