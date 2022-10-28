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
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    
    ListNode* cur_node = dummy_head;
    // need a pair i.e. the next two nodes to ops
    while (cur_node->next != nullptr && cur_node->next->next != nullptr) {
      // store the next two nodes' addr's for convenience
      ListNode* n1 = cur_node->next;
      ListNode* n2 = cur_node->next->next;
      n1->next = n2->next;
      n2->next = n1;
      cur_node->next = n2;
      cur_node = n1;
    }
    
    return dummy_head->next;
  }
};

/* Runtime: 8 ms, faster than 16.50% of C++ online submissions for Swap Nodes in Pairs.
 * Memory Usage: 7.7 MB, less than 7.26% of C++ online submissions for Swap Nodes in Pairs.
 */

