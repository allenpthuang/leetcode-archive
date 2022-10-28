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
  void add_nodes_to_heap(ListNode* head, priority_queue<int>& pq) {
    auto cur_node = head;
    while (cur_node != nullptr) {
      pq.push(cur_node->val);
      cur_node = cur_node->next;
    }
  }

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int> pq;
    for (const auto& head : lists) {
      add_nodes_to_heap(head, pq);
    }

    ListNode* cur_node = nullptr;
    ListNode* left_node;
    while (pq.size() != 0) {
      left_node = new ListNode(pq.top());
      left_node->next = cur_node;
      cur_node = left_node;
      pq.pop();
    }
    return cur_node;
  }
};

/* Runtime: 24 ms, faster than 62.39% of C++ online submissions for Merge k Sorted Lists.
 * Memory Usage: 13.8 MB, less than 27.29% of C++ online submissions for Merge k Sorted Lists.
 */

