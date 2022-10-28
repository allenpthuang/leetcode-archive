/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode* cur_node = dummy_head->next;
    ListNode* prev = dummy_head;
    while (cur_node != nullptr) {
      if (cur_node->val == val) {
        prev->next = cur_node->next;
        cur_node = prev->next;
      } else {
        prev = cur_node;
        cur_node = cur_node->next;
      }
    }
    return dummy_head->next;
  }
};

/* Runtime: 32 ms, faster than 65.82% of C++ online submissions for Remove Linked List Elements.
 * Memory Usage: 15 MB, less than 48.67% of C++ online submissions for Remove Linked List Elements.
 */

