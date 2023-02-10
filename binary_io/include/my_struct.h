#pragma once

#include <boost/serialization/vector.hpp>
#include <vector>

struct BaseDebug;
class MyStructDebug;

/* original */
struct Base {
  int a;
};

class MyStruct {
 public:
  int someInt;
  std::vector<BaseDebug> intVector;
};

/* debug derived fom original */
struct BaseDebug : Base {
  template <typename Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& a;
  }
};

class MyStructDebug : public MyStruct {
 public:
  template <typename Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& someInt;
    ar& intVector;
  }
};
