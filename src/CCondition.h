#ifndef __CCONDITION_H__
#define __CCONDITION_H__

#include <assert.h>
#include <string>

/**
* @brief    Condiion Type
* @details  Condiion Type has 2 types. One is "Pre-condition", \n
            and another is "post-condition".
*/
typedef enum {
  CONDTYPE_PRE = 0,
  CONDTYPE_POST,
} CondionType_e;

/**
* @brief    Object about some condition
* @details  CCondition. This class represent some conditions \n
            (maybe "event" type). Condition should be "pre-condition" or \n
            "post-condition". \n\n

            "Pre-condition" is checked before invoking "action" when CState \n
            received a event. If false, "receiving a event"-sequence is
            finished without action. \n\n

            "Post-condition" is checked after invoking "action" when CState \n
            received a event. If false, "receiving a event"-sequence returns \n
            "false" (this means "current state" stays on the same state).  \n
            If true, it means that CState waivers being as "current state", \n
            and next state is set as "current state".

* @image    html "../image/CCondition_PrePostAction.png"
* @cond
* @startuml CCondition_PrePostAction.png
* state CState {
* [*] -> PreCondition
* PreCondition --> [*]: Pre-Condition is true
* PreCondition -> Action
* Action -> PostCondition
* PostCondition --> [*]: Post-Condition is true
* }
* @enduml
* @endcond

* @section  Initialization

* @image    html "../image/CCondition_Initial.png"
* @cond
* @startuml CCondition_Initial.png
*
* Create CCondition
* main -> CCondition: new
* CCondition --> main:

* @enduml
* @endcond
*/
class CCondition {
private:
  CCondition(const CCondition &cond);

protected:
  const std::string &_condition;

public:
  CCondition(const std::string &str) : _condition(str){};
  virtual ~CCondition(){};
  virtual bool Meets(const std::string &target) {
    return (_condition.compare(target) == 0) ? true : false;
  };
  virtual bool Includes(const std::string &target) {
    return (_condition.find_first_of(target) == std::string::npos) ? false
                                                                   : true;
  };
};

#endif /* end of include guard: __CCONDITION_H__ */
