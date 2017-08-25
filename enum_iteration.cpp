/**
 * Compile and run:
 * g++ -std=c++14 enum_iteration.cpp -o enum_iteration.out && ./enum_iteration.out
 *
 * Can enum be iterated?
 * Yes, but it needs another function to print out its name.
 */

#include <iostream>

using namespace std;

enum State {
  STATE_FIRST = 0,
  STATE_SECOND,
  STATE_THIRD,
  ENUM_END
};

inline const char* State2Str(State v)
{
    switch (v)
    {
        case STATE_FIRST:   return "First State";
        case STATE_SECOND:   return "Second State";
        case STATE_THIRD: return "Third State";
        default:      return "[Unknown State]";
    }
}



int main() {
  for ( int state = 0; state != ENUM_END; state++ ) {
    cout << state << " " << (State)state << " " << State2Str((State)state) << endl;
  }
  // 0 0 First State
  // 1 1 Second State
  // 2 2 Third State
}