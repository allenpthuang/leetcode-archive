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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head;
    ListNode* l1_orig = l1;
    ListNode* l2_orig = l2;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val;
        l1->val = sum;
        l2->val = sum;
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1 == nullptr) {
        head = l2_orig;
        break;
      } else {
        head = l1_orig;
        break;
      }
    }
    
    ListNode* cur_node = head;
    while (cur_node != nullptr) {
      if (cur_node->val > 9) {
        if (cur_node->next == nullptr) {
          cur_node->next = new ListNode(0);
        }
        cur_node->next->val++;
        cur_node->val %= 10;
      }
      cur_node = cur_node->next;
    }
    
    return head;
  }
};

/* Runtime: 37 ms, faster than 90.04% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 70.8 MB, less than 97.66% of C++ online submissions for Add Two Numbers.
 */

