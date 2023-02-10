#include "writter.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <iostream>

void Write(const std::string& path, const MyStructDebug& data) {
  std::ofstream ofs(path, std::ios::binary);
  boost::archive::text_oarchive oa(ofs);  // binary_oarchive
  oa << data;
  ofs.close();
  return;
}
