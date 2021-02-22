#include <iostream>
#include <memory>

int main() {
  struct s_BasicObject {
    int x = 0xA3A2A1A0;
    int y = 0xB3B2B1B0;

    s_BasicObject() {
      x = 0xC3C2C1C0;
      y = 0xD3D2D1D0;
    }
  };

  // SMART POINTERS!
  // TYPE 1 - SHARED POINTER: Multiple accessors to pointer

  // Equivalent to:
  // // s_BasicObject* p_basic_obj1 = new s_BasicObject();
  std::shared_ptr<s_BasicObject> sp_basic_obj1 =
      std::make_shared<s_BasicObject>();

  {  // Scope 1
    using namespace std;
    shared_ptr<s_BasicObject> sp_basic_obj1 = make_shared<s_BasicObject>();

    {  // Scope 2
      shared_ptr<s_BasicObject> sp_basic_obj2 = sp_basic_obj1;
    }  // End Scope 2

  }  // End Scope 1

  // TYPE 2 - UNIQUE POINTER: Only ONE accessor to pointer!
  {  // Scope 1
    using namespace std;
    unique_ptr<s_BasicObject> up_basic_obj1 = make_unique<s_BasicObject>();
    {  // Scope 2
       // // Following line is invalid as ONLY ONE ACCESSOR IS ALLOWED.
       // unique_ptr<s_BasicObject> up_basic_obj2 = up_basic_obj1;
      // to make it possible to use another pointer, use `move` command!
      unique_ptr<s_BasicObject> up_basic_obj3 = move(up_basic_obj1);
    }  // End Scope 2

  }  // End Scope 1

  std::cin.get();
  return 0;
}