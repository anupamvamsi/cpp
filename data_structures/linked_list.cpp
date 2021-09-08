#include <iostream>

class Node {
 public:
  int m_data{};
  Node* m_next{nullptr};

 public:
  Node() {}
  Node(int data) : m_data{data} {}

  Node(const Node&) {}
  // https://stackoverflow.com/questions/2447696/overloading-assignment-operator-in-c
  Node& operator=(const Node&) { return *this; }

  ~Node() { std::cout << "Node deleted.\n"; }
};

class LinkedList {
 private:
  Node* m_head{nullptr};

 public:
  LinkedList() {}

  LinkedList(const LinkedList&) {}
  LinkedList& operator=(const LinkedList&) { return *this; }

  Node* getHead() { return this->m_head; }

  void insert(int data) {
    if (this->m_head == nullptr) {
      this->m_head = new Node(data);
      std::cout << "Inserted head (" << data << ") @ " << this->m_head << ".\n";
      return;
    }

    Node* current = this->m_head;
    while (current->m_next != nullptr) {
      current = current->m_next;
    }

    current->m_next = new Node(data);  // here mistakes happen
    std::cout << "Inserted node (" << data << ") @ " << current->m_next
              << ".\n";
  }

  void insert(int data, std::size_t index) {
    Node* prev = this->m_head;
    Node* temp{};
    std::size_t count{1};

    if (prev == nullptr) {  // if list empty
      std::cout << "As the list is empty, inserting (" << data
                << ") at the head.\n";
      this->insert(data);
      return;
    }

    if (index == 0) {  // insert at head
      temp = new Node();

      temp->m_data = data;
      temp->m_next = prev;

      this->m_head = temp;
      return;
    }

    while (prev->m_next != nullptr) {
      if (count == index) {
        break;
      }
      prev = prev->m_next;
      ++count;
    }

    if (count == index) {
      temp = prev->m_next;
      prev->m_next = new Node(data);

      std::cout << "Inserted node (" << data << ") @ index " << index << ", "
                << prev->m_next << ".\n";
      prev->m_next->m_next = temp;
    } else {
      std::cout << "Could not insert node (" << data << ") after ("
                << prev->m_data << ") @ " << prev
                << " as the index at which it is to be inserted (" << index
                << ") is invalid in relation to the size of the list.\n";
    }
  }

  void remove(std::size_t index) {
    Node* current{this->m_head};
    Node* prev{current};
    std::size_t count{0};

    if (current == nullptr) {
      std::cout << "Empty array, no elements to remove at index " << index
                << ".\n";
      return;
    }

    if (index == 0) {
      Node* temp{this->m_head->m_next};
      std::cout << "Removing node (" << this->m_head->m_data << ") @ index "
                << index << "...\n";
      this->m_head = nullptr;

      this->m_head = temp;

      return;
    }

    while (current->m_next != nullptr) {
      if (count == index) {
        break;
      }

      prev = current;
      current = current->m_next;
      ++count;
    }

    if (count == index) {
      Node* temp{prev->m_next};
      prev->m_next = current->m_next;
      std::cout << "Removing node (" << temp->m_data << ") @ index " << index
                << "... ";
      delete temp;
      temp = nullptr;
    } else {
      std::cout << "Could not remove node @ index " << index
                << " as the index at which it is to be inserted is invalid in "
                   "relation to the size of the list.\n";
    }
  }

  void print() {
    Node* start = this->m_head;

    std::cout << "List: ";

    if (start == nullptr) {  // empty list
      std::cout << "{}\n";
      return;
    }

    while (start->m_next != nullptr) {
      std::cout << start->m_data << " ";
      start = start->m_next;
    }
    std::cout << start->m_data << " ";

    std::cout << "\n";
  }

  std::size_t size() {
    std::size_t length{1};
    Node* start{this->m_head};

    if (start == nullptr) {
      return 0;
    }

    while (start->m_next != nullptr) {
      ++length;
      start = start->m_next;
    }

    return length;
  }

  void reverse() {
    Node *temp{this->m_head}, *current{this->m_head}, *prev{current};

    if (current == nullptr) {
      std::cout << "Empty array, no elements to reverse.\n";
      return;
    }

    current = current->m_next;  // move to second element
    prev->m_next = nullptr;     // point head.next to tail

    while (current != nullptr) {
      temp = current->m_next;
      current->m_next = prev;  // point to prev element

      prev = current;
      current = temp;
    }

    // Node* newHead{temp};

    this->m_head = prev;
    // this->m_head->m_next = nullptr;  // make head the tail
  }

  void recursiveReverse(Node* node) {
    if (node->m_next == nullptr) {
      this->m_head = node;
      return;
    }

    recursiveReverse(node->m_next);

    Node* current{node->m_next};
    current->m_next = node;
    node->m_next = nullptr;
  }

  void destroyLinkedList() {
    Node* current = this->m_head;

    if (current == nullptr) {
      std::cout << "No nodes to delete to clean up the linked list.\n";
      return;
    }

    while (current->m_next != nullptr) {
      std::cout << "Deleting node (" << current->m_data << ") @ " << current
                << "... ";
      this->m_head = current->m_next;
      delete current;
      current = this->m_head;
    }

    std::cout << "Deleting tail (" << current->m_data << ") @ " << current
              << "... ";
    this->m_head = nullptr;
  }

  ~LinkedList() {
    this->destroyLinkedList();
    std::cout << "Linked list is now deleted.\n";
    std::cout << "Size of list: " << this->size() << "\n";
  }
};

int main() {
  LinkedList list;
  std::size_t numElements{};
  int element{};

  std::cout << "Enter number of elements needed for list: ";
  std::cin >> numElements;

  for (std::size_t i{0}; i < numElements; i++) {
    std::cout << "Enter element: ";
    std::cin >> element;

    list.insert(element);
  }

  list.print();
  std::cout << "Size of list: " << list.size() << "\n";

  list.remove(3);
  list.print();

  list.insert(14, 4);
  std::cout << "Size of list: " << list.size() << "\n";

  list.print();

  list.reverse();
  std::cout << "Reversed ";
  list.print();

  list.recursiveReverse(list.getHead());
  std::cout << "Recursively reversed ";
  list.print();

  return 0;
}