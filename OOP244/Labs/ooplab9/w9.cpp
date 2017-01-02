// Workshop 9 - Virtual Functions
// w9.cpp
#include "Bus.h"
#include "Truck.h"
using namespace oop244;

int main()
{
  Vehicle* vehicle;
  vehicle = new Bus(20, 78);
  move(*vehicle);
  show(*vehicle);
  delete vehicle;
  vehicle = new Truck(30, true);
  move(*vehicle);
  show(*vehicle);
  delete vehicle;

  return 0;
}