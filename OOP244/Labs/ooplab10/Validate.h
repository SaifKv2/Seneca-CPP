#include <ctype.h>
namespace oop244 {

  template<typename T>
  bool validate(const T& minimum, const T& maximum, const T& testValue) {
    if(testValue >= minimum && maximum >= testValue) {
      return true;
    }
    else {
      return false;
    }
  }

  template<>
  bool validate<const char&>(const char& minimum, const char& maximum, const char& testValue) {

    if(toupper(testValue) >= toupper(minimum) && toupper(maximum) >= toupper(testValue)) {
      return true;
    }
    else {
      return false;
    }
  }
}