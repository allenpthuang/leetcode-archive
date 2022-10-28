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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0;
    int lenB = 0;
    ListNode* cur_node = headA;
    while (cur_node != nullptr) {
      cur_node = cur_node->next;
      lenA++;
    }
    cur_node = headB;
    while (cur_node != nullptr) {
      cur_node = cur_node->next;
      lenB++;
    }
    
    // align the rightmost
    int offset = abs(lenA - lenB);
    if (lenA >= lenB) {
      cur_node = headA;
    } else {
      cur_node = headB;
    }
    
    while (offset > 0) {
      cur_node = cur_node->next;
      offset--;
    }
    
    ListNode* cur_node_2;
    if (lenA >= lenB) {
      cur_node_2 = headB;
    } else {
      cur_node_2 = headA;
    }
    
    while (cur_node != nullptr) {
      if (cur_node == cur_node_2) {
        return cur_node;
      }
      cur_node = cur_node->next;
      cur_node_2 = cur_node_2->next;
    }
    return cur_node;
  }
};

/* Runtime: 37 ms, faster than 99.66% of C++ online submissions for Intersection of Two Linked Lists.
 * Memory Usage: 14.4 MB, less than 98.89% of C++ online submissions for Intersection of Two Linked Lists.
 */

