#include <iostream>

// USING ARRAYS
int main() {
  // Polymorphism = ability of one obj to look and behave like another!
  struct s_SomeBasicObject {
    // Adding `virtual` enables child structs to call their methods!
    virtual const char* IDYourself() {  //
      return "BasicObject";
    }

    virtual ~s_SomeBasicObject() {}  // added for better code
  };

  struct s_SomeSubObjA : public s_SomeBasicObject {
    virtual const char* IDYourself() override {  //
      return "SubObj A!";
    }
  };

  struct s_SomeSubObjB : public s_SomeBasicObject {
    virtual const char* IDYourself() override {  //
      return "SubObj B...";
    }
  };

  // s_SomeBasicObject ob_basic;
  // s_SomeSubObjA ob_A;
  // s_SomeSubObjB ob_B;

  // std::cout << ob_basic.IDYourself() << std::endl;
  // std::cout << ob_A.IDYourself() << std::endl;
  // std::cout << ob_B.IDYourself() << std::endl;

  // s_SomeBasicObject obj_array[10];
  // // force one of the base objs to be objA:
  // // this object will still not call the child struct's overloaded
  // // function!
  // obj_array[3] = s_SomeSubObjA();

  // for (int i = 0; i < 10; i++) {
  //   std::cout << obj_array[i].IDYourself() << std::endl;
  // }

  // 1. allocate the array
  s_SomeBasicObject** p_some_array_ptr = new s_SomeBasicObject*[5];

  // 2. individually create the objects!
  // You can either do this:
  // for (int i = 0; i < 5; i++) {
  //   p_some_array_ptr[i] = new s_SomeBasicObject();
  // }
  // OR this (to create a mix of base and sub objects!):
  // <pointers to array elements OK. pointers to vec elements BAD.>
  p_some_array_ptr[0] = new s_SomeSubObjA();
  p_some_array_ptr[1] = new s_SomeSubObjB();
  p_some_array_ptr[2] = new s_SomeSubObjB();
  p_some_array_ptr[3] = new s_SomeBasicObject();
  p_some_array_ptr[4] = new s_SomeSubObjA();

  for (int i = 0; i < 5; i++) {
    // when calling a method while using a pointer, use "->" operator
    std::cout << p_some_array_ptr[i]->IDYourself() << std::endl;
  }

  // Be a good person and free the memory!
  // To delete the individual pointer objects:
  for (int i = 0; i < 5; i++) {
    delete p_some_array_ptr[i];
  }

  // delete the pointer array too!
  delete[] p_some_array_ptr;

  std::cin.get();
  return 0;
}