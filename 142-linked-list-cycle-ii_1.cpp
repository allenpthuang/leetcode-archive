/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> st;
    while (head != nullptr) {
      if (st.count(head) > 0) {
        return head;
      }
      st.insert(head);
      head = head->next;
    }

    return head;
  }
};

/* Runtime: 37 ms, faster than 5.36% of C++ online submissions for Linked List Cycle II.
 * Memory Usage: 9.3 MB, less than 21.01% of C++ online submissions for Linked List Cycle II.
 */

