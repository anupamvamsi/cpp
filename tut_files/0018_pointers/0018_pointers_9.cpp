#include <iostream>

// Passing by const reference
int* Add(const int& a, const int& b) {
  int* c;
  // Dynamically allocate mem of c on heap
  // This means value @address of c will not be deallocated
  // until 'delete' is called on the address of c, as c is on
  // the heap.
  c = new int;  // Basically, c = (int*)malloc(sizeof(int));

  *c = a + b;
  std::cout << "Add : a: " << &a << " b: " << &b << std::endl;
  // THIS IS BAD! YOU ARE RETURNING ADDRESS OF A LOCAL VARIABLE!
  // IT IS BAD BECAUSE LOCAL VARIABLES GET *TERMINATED*!
  // (considering return type of 'Add' is "int*")
  // return &c;
  return c;
}

int main() {
  int x = 3, y = 5;
  int* z = Add(x, y);
  std::cout << "Main: x: " << &x << " y: " << &y << std::endl;
  std::cout << "Sum = " << *z << std::endl;
  std::cout << (intptr_t)z << std::endl;
  delete z;     // free(z); // calling delete on 'c' in Add, basically
                // Now it is a dangling pointer!
                // If `delete z;` is not called, this opens up to memory
                // leaks!
  z = nullptr;  // To avoid dangling pointers!
                // This assignment to `nullptr` is not needed since z
                // almost immediately goes out of scope, and gets
                // destroyed!
  std::cout << (intptr_t)z << std::endl;

  std::cin.get();
}

// Additional notes (learncpp.com):
// 1. Use pass by reference when when there is a situation you are using
// large structs or classes, and it will consume time in copying them over
// if you use pass by value or pass by address.
// Otherwise, it is syntactically more clear to use pass by address instead
// of pass by reference.
// 2. Use const pass by reference if you know you aren't going to modify the
// value of the variable within the function.
// 3. Pass by references can be used to return multiple values.
// 4. References must be initialized, so no need to worry about NULL values.