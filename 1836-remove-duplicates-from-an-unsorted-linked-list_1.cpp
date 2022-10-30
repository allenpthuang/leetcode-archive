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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int, int> freq;
    ListNode* cur_node = head;
    while (cur_node != nullptr) {
      freq[cur_node->val]++;
      cur_node = cur_node->next;
    }
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode* prev_node = dummy_head;
    cur_node = head;
    while (cur_node != nullptr) {
      if (freq[cur_node->val] > 1) {
        prev_node->next = cur_node->next;
        cur_node = cur_node->next;
      } else {
        prev_node = cur_node;
        cur_node = cur_node->next;
      }
    }
    return dummy_head->next;
  }
};

/* Runtime: 605 ms, faster than 92.67% of C++ online submissions for Remove Duplicates From an Unsorted Linked List.
 * Memory Usage: 165.5 MB, less than 90.91% of C++ online submissions for Remove Duplicates From an Unsorted Linked List.
 */

