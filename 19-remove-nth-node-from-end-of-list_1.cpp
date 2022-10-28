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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    
    ListNode* cur_node = dummy_head;
    while (cur_node != nullptr) {
      if (cur_node->next != nullptr && cur_node->next->val == n) {
        cur_node->next = cur_node->next->next;
      }
      cur_node = cur_node->next;
    }
    return dummy_head->next;
  }
};

/* wrong answer; this should be removing val == n... */
