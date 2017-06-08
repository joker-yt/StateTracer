#ifndef __CCONDITION_GROUP_H__
#define __CCONDITION_GROUP_H__

#include <string>
#include <assert.h>

/**
* @brief CConditionGroup
* @details CConditionGroup has some "conditions" inside.
*/
class CConditionGroup {
public:
  CConditionGroup(){};

  virtual ~CConditionGroup(){};
  CConditionGroup(const CConditionGroup &other){};
  CConditionGroup(CConditionGroup &&other) { assert(1); };
  CConditionGroup &operator=(const CConditionGroup &other) = default;
  CConditionGroup &operator=(CConditionGroup &&other) = default;
  void Request(){};
  void SetNext(CConditionGroup &next){};

protected:
  const CConditionGroup *_p_next;
};

#endif /* end of include guard: __CCONDITION_GROUP_H__ */
