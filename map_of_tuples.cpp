/**
 * Compile and run:
 * g++ -std=c++14 map_of_tuples.cpp -o map_of_tuples.out && ./map_of_tuples.out
 * 
 * How to create and use map of tuples?
 *
 * In python, this is as simple as:
 * tm = {
 *   "key1": ("hello", 1)
 * }
 *
 * Let's see how "easy" it is in C++.
 */

#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, std::tuple<std::string, int>> TupleMap;

int main() {
  TupleMap tm;
  // Tuple object needs to be defined first and then added to map:
  std::tuple<std::string, int> t;
  std::get<0>(t) = "hello";
  std::get<1>(t) = 1;
  tm["key1"] = t;

  // And to use:
  std::cout << std::get<0>(tm["key1"]) << " " << std::get<1>(tm["key1"]) << std::endl;
  // hello 1

  // Map can also be iteratively looped:
  std::get<0>(t) = "bye";
  std::get<1>(t) = 2;
  tm["key2"] = t;

  for (TupleMap::iterator it=tm.begin(); it!=tm.end(); ++it)
    std::cout << it->first << " => " <<
      std::get<0>(it->second) << ' ' <<
      std::get<1>(it->second) << std::endl;
  // key1 => hello 1
  // key2 => bye 2

}

// That was cryptic.
