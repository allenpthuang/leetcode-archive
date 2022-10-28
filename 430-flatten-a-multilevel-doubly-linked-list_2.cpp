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
 public:
  Node* flatten(Node* head) {
    Node* dummy_head = new Node();
    stack<Node*> st;
    if (head != nullptr) {
      st.push(head);
    } else {
      return head;
    }
    Node* cur_node = dummy_head;
    while (! st.empty()) {
      Node* top = st.top();
      st.pop();
      cur_node->next = top;
      top->prev = cur_node;
      if (top->next != nullptr) {
        st.push(top->next);
      }
      if (top->child != nullptr) {
        st.push(top->child);
        top->child = nullptr;
      }
      cur_node = cur_node->next;
    }
    cur_node->next = nullptr;
    dummy_head->next->prev = nullptr;
    return dummy_head->next;
  }
};

/* Runtime: 3 ms, faster than 91.79% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 * Memory Usage: 7.4 MB, less than 21.29% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 */

