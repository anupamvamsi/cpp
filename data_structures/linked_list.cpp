#include <iostream>

class Node {
 public:
  int m_data;
  Node* m_next{nullptr};

 public:
  Node() {}
  Node(int data) : m_data{data} {}
  ~Node() { std::cout << "Node deleted.\n"; }
};

class LinkedList {
 private:
  Node* m_head = nullptr;

 public:
  LinkedList() {}

  void Insert(int data) {
    if (this->m_head == nullptr) {
      this->m_head = new Node(data);
      std::cout << "Inserted head @ " << this->m_head << '\n';
      return;  // make function stop and not execute the statements after 'if'
    }

    Node* current = this->m_head;
    while (current->m_next != nullptr) {
      current = current->m_next;
    }

    current->m_next = new Node(data);  // here mistakes happen
    std::cout << "Inserted node @ " << current->m_next << '\n';
  }

  void Insert(int data, int index) {
    Node* prev = this->m_head;
    Node* temp;
    int count{1};

    if (prev == nullptr) {  // if list empty
      this->Insert(data);
      return;
    }

    while (prev->m_next != nullptr) {
      prev = prev->m_next;
      count++;

      if (count == index) {
        break;
      }
    }

    temp = prev->m_next;
    prev->m_next = new Node(data);

    std::cout << "Inserted node @ " << prev->m_next << '\n';
    prev->m_next->m_next = temp;
  }

  void Print() {
    Node* start = this->m_head;

    if (start == nullptr) {  // empty list
      std::cout << "{}\n";
      return;
    }

    while (true) {
      std::cout << start->m_data << " ";

      if (start->m_next == nullptr) {
        break;
      }

      start = start->m_next;
    }

    std::cout << '\n';
  }

  void DestroyLinkedList() {
    Node* current = this->m_head;

    while (current->m_next != nullptr) {
      std::cout << "Deleting node @ " << current << "... ";
      this->m_head = current->m_next;
      delete current;
      current = this->m_head;
    }

    std::cout << "Deleting tail @ " << current << "... ";
    delete this->m_head;
  }

  ~LinkedList() {
    this->DestroyLinkedList();
    std::cout << "Linked list is now deleted.\n";
  }
};

int main() {
  LinkedList list;
  int num_elements{0}, element{0};

  std::cout << "Enter number of elements needed for list: ";
  std::cin >> num_elements;

  for (int i{0}; i < num_elements; i++) {
    std::cout << "Enter element: ";
    std::cin >> element;

    list.Insert(element);
  }

  list.Print();

  list.Insert(14, 3);

  list.Print();

  return 0;
}