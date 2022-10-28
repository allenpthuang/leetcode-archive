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
    unordered_set<ListNode*> st;
    ListNode* cur_node = headA;
    while (cur_node != nullptr) {
      st.insert(cur_node);
      cur_node = cur_node->next;
    }
    cur_node = headB;
    while (cur_node != nullptr) {
      if (st.count(cur_node) > 0) {
        return cur_node;
      } else {
        cur_node = cur_node->next;
      }
    }
    return cur_node;
  }
};

/* Runtime: 88 ms, faster than 35.35% of C++ online submissions for Intersection of Two Linked Lists.
 * Memory Usage: 17.3 MB, less than 13.64% of C++ online submissions for Intersection of Two Linked Lists.
 */
