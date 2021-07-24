#include <iostream>

int main() {
  struct s_SomeObject {
    unsigned int x = 0xA3A2A1A0;
    unsigned int y = 0xB3B2B1B0;

    s_SomeObject() {
      x = 0xC3C2C1C0;
      y = 0xD3D2D1D0;
    }  // this is called
  };

  // STACK ALLOCATION
  // || Good for compile time allocation of memory!
  // || The memory created by the array is on a stack
  // || By initializing the array with a number, it is known at compile
  // || time num of objects required
  // s_SomeObject i_some_object[10];

  // HEAP ALLOCATION
  // || Good for run time allocation of memory!
  // || We do not know at compile time the num of objects required
  // || To allocate on a heap we'll need a pointer!
  // || The pointer is going to point to the Zeroth element of the array
  // || of 10 s_SomeObjects. The `new` keyword returns a pointer!
  s_SomeObject* p_some_object = new s_SomeObject[10];

  // Whenever we request memory from the OS at run time we need
  // to release the memory! Here, we know where the memory is, @pointer,
  // i.e., p_some_object's value (which has the address, obviously)
  delete[] p_some_object;

  // Array of Pointers with allocation at Run Time
  // Where would/could we use the following line of code? => Polymorphism!
  // Check RPG series!
  s_SomeObject** p_some_object_ptr_arr = new s_SomeObject* [10] { 0 };

  // for each element of pointer array, create a new object
  for (int i = 0; i < 10; i++) {
    p_some_object_ptr_arr[i] = new s_SomeObject();
  }  // memory addresses are allocated

  // need to delete the individual objects that were created above!
  for (int i = 0; i < 10; i++) {
    delete p_some_object_ptr_arr[i];
  }

  // overall array delete only deletes array of pointers!
  delete[] p_some_object_ptr_arr;

  std::cin.get();
  return 0;
}