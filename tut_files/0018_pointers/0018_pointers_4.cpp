#include <iostream>
#include <vector>

// USING VECTORS
int main() {
  struct s_BasicObject {
    virtual const char* IDYourself() {  //
      return "BasicObject";
    }
  };

  struct s_SubObjectA : public s_BasicObject {
    const char* IDYourself() {  //
      return "Sub Object A!";
    }
  };

  struct s_SubObjectB : public s_BasicObject {
    const char* IDYourself() {  //
      return "Sub Object B...";
    }
  };

  std::vector<s_BasicObject*> v_pointer_vector;

  v_pointer_vector.push_back(new s_SubObjectA());
  v_pointer_vector.push_back(new s_SubObjectB());
  v_pointer_vector.push_back(new s_SubObjectB());
  v_pointer_vector.push_back(new s_BasicObject());
  v_pointer_vector.push_back(new s_SubObjectA());

  for (auto& a : v_pointer_vector) {
    // `a` is passed by reference as we do not want to make a copy
    // delete the copy! Instead, we want to delete the original value!
    std::cout << a->IDYourself() << std::endl;
  }

  for (auto& a : v_pointer_vector) {
    delete a;
  }

  // to get rid of vector's memory and it's size
  v_pointer_vector.clear();

  std::cin.get();
  return 0;
}