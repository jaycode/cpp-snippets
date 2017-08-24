/**
 * Compile and run:
 * g++ -std=c++14 alias_of_struct.cpp -o alias_of_struct.out && ./alias_of_struct.out
 *
 * This snippet checks if a value inside a struct can be aliased
 * from a class variable.
 * The answer is: yes, it is possible!
 *
 * And what happens if we update the alias variable?
 * The original variable is also updated.
 */
#include <iostream>

struct bar {
    int x = 1;
};

class foo {
  public:
    bar b;
    int& x = b.x;
    
    foo(bar b) {
        this->b = b;
    }
};

int main()
{
    bar b;
    b.x = 2;
    foo f = foo(b);
    // Value of alias member x is the same with x of f.b
    std::cout <<"x of f: "<< f.x << " x of f.b: " << f.b.x <<  "\n";
    // x of f: 2 x of f.b: 2

    // And if we update the alias, the original variable is also updated.
    // (unless if we use `const int& x = b.x` above)
    f.x = 3;
    std::cout <<"x of f: "<< f.x << " x of f.b: " << f.b.x <<  "\n";
    // x of f: 3 x of f.b: 3
}
