class Node {
 public:
  int val;
  Node* next;
  Node() {
    val = 0;
    next = nullptr;
  }
};

class MyLinkedList {
 public:
  Node* head;

  MyLinkedList() {
    head = new Node();
  }
  
  int get(int index) {
    Node* cur_node = head->next;
    for (int i = 0; i < index; i++) {
      cur_node = cur_node->next;
      if (cur_node == nullptr) {
        return -1;
      }
    }
    if (cur_node == nullptr) return -1;
    return cur_node->val;
  }
  
  void addAtHead(int val) {
    Node* new_head = new Node();
    new_head->val = val;
    new_head->next = head->next;
    head->next = new_head;
  }
  
  void addAtTail(int val) {
    Node* cur_node = head->next;
    Node* prev = head;
    while (cur_node != nullptr) {
      prev = cur_node;
      cur_node = cur_node->next;
    }
    Node* new_tail = new Node();
    new_tail->val = val;
    prev->next = new_tail;
  }
  
  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    Node* cur_node = head->next;
    Node* prev = head;
    for (int i = 0; i < index; i++) {
      if (cur_node == nullptr) return;
      prev = cur_node;
      cur_node = cur_node->next;
      if (cur_node == nullptr && i != index - 1) {
        return;
      }
    }
    Node* new_node = new Node();
    new_node->val = val;
    new_node->next = cur_node;
    prev->next = new_node;
  }
  
  void deleteAtIndex(int index) {
    Node* cur_node = head->next;
    Node* prev = head;
    if (cur_node == nullptr) return;
    for (int i = 0; i < index; i++) {
      prev = cur_node;
      cur_node = cur_node->next;
      if (cur_node == nullptr) return;
    }
    prev->next = cur_node->next;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/* Runtime: 66 ms, faster than 45.67% of C++ online submissions for Design Linked List.
 * Memory Usage: 19.7 MB, less than 28.62% of C++ online submissions for Design Linked List.
 */

