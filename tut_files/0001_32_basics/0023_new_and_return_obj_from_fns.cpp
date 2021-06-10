#include <iostream>

class Animal {
 private:
  std::string name;

 public:
  Animal() { std::cout << "Animal created!" << std::endl; }

  Animal(const Animal& other) : name{other.name} {
    std::cout << "Animal created with copy constructor. The name " << name
              << " is assigned to the new Animal." << std::endl;
  }

  ~Animal() { std::cout << name << " destroyed." << std::endl; }

  void SetName(std::string name) { this->name = name; }

  void Speak() { std::cout << name << " says hello!" << std::endl; }
};

// Return an object from an independent function:
Animal* CreateAnimal() {
  Animal* ptr_a = new Animal();
  ptr_a->SetName("Jambudi");
  return ptr_a;
}

void DestroyAnimal(Animal* ptr_animal) {
  delete ptr_animal;
  ptr_animal = nullptr;
}

int main() {
  {
    Animal croc1;
    croc1.SetName("Crocko");
    croc1.Speak();

    std::cout << std::endl;

    Animal* ptr_croc2 = new Animal();
    ptr_croc2->SetName("Crocki");
    ptr_croc2->Speak();

    std::cin.get();
    // size of a pointer is 8 bytes
    std::cout << "Size of pointer: ";
    std::cout << sizeof(ptr_croc2) << " Bytes." << std::endl;

    // ptr_croc2->~Animal();
    delete ptr_croc2;
    ptr_croc2 = nullptr;

    std::cout << std::endl;

    Animal* croc3 = CreateAnimal();
    croc3->Speak();
    DestroyAnimal(croc3);
  }

  std::cin.ignore();
  std::cin.get();
}