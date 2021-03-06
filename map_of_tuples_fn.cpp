/**
 * Compile and run:
 * g++ -std=c++14 map_of_tuples_fn.cpp -o map_of_tuples_fn.out && ./map_of_tuples_fn.out
 * 
 * This is similar to map_of_tuples.cpp but I'd like to pass in function reference
 * to one of the tuple elements.
 *
 * In python, this is as simple as:
 * def fun(num):
 *   return num
 * tm = {
 *   "key1": ("hello", fun)
 * }
 */

#include <iostream>
#include <string>
#include <map>

int fun(int num) {
  return num;
}
typedef std::map<std::string, std::tuple<std::string, int(*)(int)>> TupleMap;

int main() {
  TupleMap tm;
  // Tuple object needs to be defined first and then added to map:
  std::tuple<std::string, int(*)(int)> t;
  std::get<0>(t) = "hello";
  std::get<1>(t) = fun;
  tm["key1"] = t;

  // To use:
  std::cout << std::get<0>(tm["key1"]) << " " <<
    std::get<1>(tm["key1"])(1) << std::endl;
  // hello 1
}

// The main takeaway from here is the use of `int(*)()` to generalize
// a function pointer.