#include <iostream>
#include <vector>

class Label {
 private:
  char name;

 public:
  Label();
  Label(char name) : name(name) {
    std::cout << "Label " << name << " attached." << std::endl;
  }
  ~Label() { std::cout << "Label " << name << " removed." << std::endl; }

  // void SetLabel(char name) { this->name = name; }
  void ShowLabel() { std::cout << "Label: " << name << std::endl; }
};

Label* CreateLabel(char alph) {
  Label* new_label = new Label(alph);

  return new_label;
}

int main() {
  char c{65};
  // vector of Label object pointers
  std::vector<Label*> label_ptr;

  for (int i = 0; i < 26; i++) {
    label_ptr.push_back(CreateLabel(c++));
  }

  for (auto& label_obj : label_ptr) {
    label_obj->ShowLabel();
  }

  for (auto& label_obj : label_ptr) {
    delete label_obj;
    label_obj = nullptr;
  }

  std::cout << std::endl;

  for (auto& label_obj : label_ptr) {
    std::cout << label_obj << " ";
  }

  label_ptr.clear();

  std::cin.get();
}