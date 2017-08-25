/**
 * Compile and run:
 * g++ -std=c++14 child_to_parent.cpp -o child_to_parent.out && ./child_to_parent.out
 *
 * Can we pass child class when the function requires parent class?
 * Nope. The function has to request child class i.e. in the code below, use
 * CarConfig and BicycleConfig instead of Config for the constructors.
 */
#include <iostream>

struct Config {
  int num_of_wheels = 4;
};

struct CarConfig : Config {
  bool manual_gear = true;
};

struct BicycleConfig : Config {
  bool steel_skeleton = false;
};

class Vehicle {
 public:
  Vehicle() {
    std::cout << "vehicle empty constructor\n";
  }
  Vehicle(Config config) {
    std::cout << "vehicle non-empty constructor\n";
    this->config = config;
  }
  Config config;
};

class Car : public Vehicle {
 public:

  // This constructor function also calls
  // `Vehicle()`, that is why we need to create
  // `Vehicle() {}` constructor at the parent above.
  Car(CarConfig config) {
    std::cout << "car constructor\n";
    this->config = config;
  }
  // Remember to redefine the child's member variable again.
  CarConfig config;
};

class Bicycle : public Vehicle {
 public:
  Bicycle(BicycleConfig config) {
    std::cout << "bicycle constructor\n";
    this->config = config;
  }
  BicycleConfig config;
};

int main() {
  CarConfig car_config;
  BicycleConfig bicycle_config;
  bicycle_config.num_of_wheels = 2;

  Car car = Car(car_config);
  Bicycle bicycle = Bicycle(bicycle_config);

  std::cout << "Car num of wheels: " << car.config.num_of_wheels << "\n";
  std::cout << "Car manual_gear: " << car.config.manual_gear << "\n";
  std::cout << "Bicycle num of wheels: " << bicycle.config.num_of_wheels << "\n";
  std::cout << "Bicycle steel_skeleton: " << bicycle.config.steel_skeleton << "\n";
  // vehicle empty constructor
  // car constructor
  // vehicle empty constructor
  // bicycle constructor
  // Car num of wheels: 4
  // Car manual_gear: 1
  // Bicycle num of wheels: 2
  // Bicycle steel_skeleton: 0

}