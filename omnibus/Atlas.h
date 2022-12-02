#ifndef ATLAS_H
#define ATLAS_H

#include <istream>
#include <string>
#include <map>

#include "Trip.h"
#include "Helpers.h"


class Atlas {
public:
  // Required Class Function
  static Atlas* create(std::istream& stream);

private:
  // Member Variables
  std::map<std::string, Station*> atlas;

public:
  // Constructor & Destructor
  Atlas(std::istream& stream);
  ~Atlas();

  // Required Member Function
  Trip route(const std::string& src, const std::string& dst);
};

#endif
