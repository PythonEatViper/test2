#include "reader.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <iostream>

MyStructDebug Read(std::string path) {
  MyStructDebug deserialized;
  std::ifstream ifs(path, std::ios::binary);
  boost::archive::text_iarchive ia(ifs);  // binary_iarchive
  ia >> deserialized;
  ifs.close();
  return deserialized;
}
