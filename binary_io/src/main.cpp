#include <iostream>

#include "my_struct.h"
#include "reader.h"
#include "writter.h"

int main(int argc, char** argv) {
  std::string path = "/debug/boost_serializtion/data.bin";
  MyStructDebug data;
  data.someInt = 100;
  {
    BaseDebug t;
    t.a = 1;
    data.intVector.push_back(t);
  }
  {
    BaseDebug t;
    t.a = 2;
    data.intVector.push_back(t);
  }

  // Serialize to a file
  Write(path, data);

  // Deserialize from a file
  MyStructDebug deserialized = Read(path);

  std::cout << "Deserialized: " << std::endl;
  for (const auto& a : deserialized.intVector) {
    std::cout << a.a << std::endl;
  }

  return 0;
}
