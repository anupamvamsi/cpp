#include <iostream>

class Node {
 public:
  int m_data;
  Node* m_next;

 public:
  Node(int d) : m_data{d}, m_next{nullptr} {}

  ~Node() {}
};

class LinkedList {
 public:
  Node* Insert(Node* head, int data) {
    if (head == nullptr) {
      head = new Node(data);

      return head;
    }

    Node* temp_node = head;
    while (temp_node->m_next != nullptr) {  // Traversing the list until the end
                                            // to add elements at the end
      // std::cout << temp_node << std::endl;
      temp_node = temp_node->m_next;
    }

    temp_node->m_next = new Node(data);
    return head;
  }

  Node* Insert(Node* head, int data, int index) {
    int count = 1;

    Node* temp_node = head;
    while (true) {
      temp_node = temp_node->m_next;
      count++;

      if (count == index) {
        break;
      }
    }

    Node* temp_loc = temp_node->m_next;
    temp_node->m_next = new Node(data);
    temp_node->m_next->m_next = temp_loc;

    return head;
  }

  void Display(Node* head) {
    Node* start = head;

    while (start) {
      std::cout << start->m_data << " ";
      start = start->m_next;
    }
    std::cout << "\n";
  }
};

int main() {
  Node* head = nullptr;
  LinkedList list;

  int T;
  int data;

  std::cin >> T;

  while (T-- > 0) {
    std::cin >> data;
    head = list.Insert(head, data);
  }

  std::cout << "Head: " << head << std::endl;
  list.Display(head);

  std::cin >> data;
  list.Insert(head, data, 2);
  list.Display(head);
}

/*
Sample Input

STDIN   Function
-----   --------
4       T = 4
2       first data = 2
3
4
1       fourth data = 1

Sample Output

2 3 4 1

*/