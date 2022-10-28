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
    
    ListNode* fast = dummy_head;
    ListNode* slow = dummy_head;
    // fast-forward the fast pointer first
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }
    // move both until fast->next hits nullptr
    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    
    // now fast->next is nullptr, and slow->next is the one to be removed
    slow->next = slow->next->next;
    
    return dummy_head->next;
  }
};

/* Runtime: 3 ms, faster than 90.84% of C++ online submissions for Remove Nth Node From End of List.
 * Memory Usage: 10.8 MB, less than 32.56% of C++ online submissions for Remove Nth Node From End of List.
 */

