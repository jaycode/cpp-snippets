/**
 * Compile and run:
 * g++ object_parameters.cpp -o object_parameters.out && ./object_parameters.out
 *
 * How to pass objects as parameters to a function with Google C++ standard?
 * https://google.github.io/styleguide/cppguide.html#Reference_Arguments
 * Conclusion: Though a bit more verbose, the guide adds clarity in the call side.
 */

#include <iostream>
#include <vector>

using namespace std;

void Test(const vector<double> &in, vector<double> *out) {
  cout << "in: " << in[0] << endl;
  // in: 1
  
  cout << "out: " << out << endl;
  // out1: 0x7ffc45be1360after

  cout << "(*out): " << (*out)[0] << endl;
  // out2: 1

  // This is the only way to update.
  (*out)[0] = 2.0;
}

int main() {
  vector<double> in;
  in.push_back(1.0);
  vector<double> out;
  out.push_back(1.0);

  // The reason Google C++ guide is better is in the call side
  // such as this code, it is clear variable `out` is mutable:
  Test(in, &out);
  cout << "after Test out: " << out[0] << endl;
  // after Test out: 2
  return 0;
}
