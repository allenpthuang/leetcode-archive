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
  ListNode* reverseList(ListNode* head) {
    ListNode* cur_node = head;
    ListNode* prev_node = nullptr;
    while (cur_node != nullptr) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }
    return prev_node;
  }
};

/* Runtime: 3 ms, faster than 98.40% of C++ online submissions for Reverse Linked List.
 * Memory Usage: 8.1 MB, less than 99.98% of C++ online submissions for Reverse Linked List.
 */

