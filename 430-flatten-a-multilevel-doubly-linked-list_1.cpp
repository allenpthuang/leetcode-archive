/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 private:
  Node* walker(Node* cur_node, Node* to_be_continued) {
    if (cur_node == nullptr) {
      return to_be_continued;
    }
    cur_node->next = walker(cur_node->child, walker(cur_node->next, to_be_continued));
    if (cur_node->next != nullptr) {
      cur_node->next->prev = cur_node;
    }
    cur_node->child = nullptr;
    return cur_node;
  }
 public:
  Node* flatten(Node* head) {
    return walker(head, nullptr);
  }
};

/* Runtime: 3 ms, faster than 91.79% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 * Memory Usage: 7.4 MB, less than 64.06% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 */

