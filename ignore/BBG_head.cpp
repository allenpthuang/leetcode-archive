==> 797-all-paths-from-source-to-target_1.cpp <==
class Solution {
 private:
  void worker(vector<vector<int> >& graph, vector<vector<int> >& paths, vector<int>& cur_path, int src, int dst) {
    if (src == dst) {
      paths.push_back(cur_path);
      return;
    }
    for (const auto& next_src : graph[src]) {
      cur_path.push_back(next_src);
      worker(graph, paths, cur_path, next_src, dst);
      cur_path.pop_back();
    }
  }
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int> > paths;
    vector<int> cur_path = {0};
    worker(graph, paths, cur_path, 0, graph.size() - 1);
    return paths;
  }
};

/* Runtime: 28 ms, faster than 48.61% of C++ online submissions for All Paths From Source to Target.
 * Memory Usage: 10.6 MB, less than 81.92% of C++ online submissions for All Paths From Source to Target.
 */


==> 1209-remove-all-adjacent-duplicates-in-string-ii_1.cpp <==
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int> > st;  // char, count
    for (const auto& ch : s) {
      if (st.empty() || st.back().first != ch) {
        st.push_back({ch, 1});
      } else if (st.back().second == k - 1) {
        st.pop_back();
      } else {
        st.back().second++;
      }
    }
    string result = "";
    for (auto& [ch, count] : st) {
      for (; count > 0; count--) {
        result += ch;
      }
    }
    return result;
  }
};

/* Runtime: 20 ms, faster than 91.36% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 * Memory Usage: 10.6 MB, less than 53.10% of C++ online submissions for Remove All Adjacent Duplicates in String II.
 */


==> 787-cheapest-flights-within-k-stops_2.cpp <==
class Solution {
 private:
  int worker(unordered_map<int, unordered_map<int , int> >& prices, unordered_set<int>& visited, int src, int dst, int cur_cost, int rem_legs) {
    if (src == dst) {
      return cur_cost;
    }
    if (rem_legs == 0 || visited.find(src) != visited.end() || prices.find(src) == prices.end()) {
      return INT_MAX;
    }
    
    visited.insert(src);
    int cur_min = INT_MAX;
    for (const auto& [next_dst, price] : prices[src]) {
      cur_min = min(cur_min, worker(prices, visited, next_dst, dst, cur_cost + price, rem_legs - 1));
    }
    return cur_min;
  }
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    unordered_map<int, unordered_map<int, int> > prices;  // src -> (dst -> price)
    for (const auto& flight : flights) {
      prices[flight[0]][flight[1]] = flight[2];
    }
    
    unordered_set<int> visited;
    int result = worker(prices, visited, src, dst, 0, k + 1);
    if (result == INT_MAX) {
      return -1;
    } else {
      return result;
    }
  }
};

/* wrong answer */


==> 1105-filling-bookcase-shelves_1.cpp <==
class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    vector<int> dp(books.size() + 1, INT_MAX);  // dp[k]: min total height at k-th book, k strating from 1
    dp[0] = 0;  // zero-th book requires 0 height
    
    for (int i = 0; i < books.size(); i++) {
      // dp[k] = dp[k - 1] + books[i][1], where k = i + 1
      // assume we put the book at a new level first
      dp[i + 1] = dp[i] + books[i][1];
      
      int cur_width = books[i][0];
      int cur_tallest = books[i][1];
      for (int j = i - 1; j >= 0; j--) {  // go thru previous books
        cur_width += books[j][0];
        cur_tallest = max(cur_tallest, books[j][1]);
        // this works because eventually we are going to use dp[j] at the previous level,
        // and that j-th book would be the one just before the shelf explodes
        if (cur_width <= shelfWidth) {
          dp[i + 1] = min(dp[i + 1], dp[j] + cur_tallest);
        }
      }
    }
    return dp[books.size()];
  }
};

/* Runtime: 26 ms, faster than 11.78% of C++ online submissions for Filling Bookcase Shelves.
 * Memory Usage: 8.1 MB, less than 95.11% of C++ online submissions for Filling Bookcase Shelves.
 */


==> 146-lru-cache_3.cpp <==
class LRUCache {
 private:
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> pos;
  list<int> lru_keys;
  int capacity;
  
  void remove_key(int key) {
    auto it = pos[key];
    lru_keys.erase(it);
    pos.erase(key);
  }
  
  void add_key(int key) {
    lru_keys.push_front(key);
    pos[key] = lru_keys.begin();
  }

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }
    if (key == lru_keys.front()) {
      return cache[key];
    }
    // update lru_keys
    remove_key(key);
    add_key(key);
    
    return cache[key];
  }

  void put(int key, int value) {
    // if the key exists
    if (cache.find(key) != cache.end()) {
      if (key == lru_keys.front()) {
        cache[key] = value;
        return;
      }
      // erase from lru_keys
      remove_key(key);
      capacity++;
    } else if (capacity == 0) {  // cache is full
      // erase from lru_keys
      int key_to_evict = lru_keys.back();
      remove_key(key_to_evict);
      cache.erase(key_to_evict);
      capacity++;
    }
    cache[key] = value;
    // put back to lru_keys
    // capacity decreases again
    add_key(key);
    capacity--;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* Runtime: 614 ms, faster than 55.32% of C++ online submissions for LRU Cache.
 * Memory Usage: 184.8 MB, less than 5.18% of C++ online submissions for LRU Cache.
 */

/* change from count() to find() in unordered_map */


==> 238-product-of-array-except-self_2.cpp <==
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
      result[i] *= prefix;
      prefix *= nums[i];
    }
    int postfix = 1;
    for (int i = result.size() - 1; i >= 0; i--) {
      result[i] *= postfix;
      postfix *= nums[i];
    }
    return result;
  }
};

/* Runtime: 28 ms, faster than 87.34% of C++ online submissions for Product of Array Except Self.
 * Memory Usage: 24 MB, less than 69.16% of C++ online submissions for Product of Array Except Self.
 */


==> 1143-longest-common-subsequence_1.cpp <==
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    
    for (int i = text1.size() - 1; i >= 0; i--) {
      for (int j = text2.size() - 1; j >= 0; j--) {
        if (text1[i] == text2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else {
          dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp[0][0];
  }
};

/* Runtime: 56 ms, faster than 25.80% of C++ online submissions for Longest Common Subsequence.
 * Memory Usage: 13 MB, less than 45.56% of C++ online submissions for Longest Common Subsequence.
 */


==> 713-subarray-product-less-than-k_1.cpp <==
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) {
      return 0;
    }
    // sliding window
    int count = 0;
    int left = 0;
    int cur_product = 1;
    for (int right = 0; right < nums.size(); right++) {
      cur_product *= nums[right];
      while (cur_product >= k && left <= right) {
        cur_product /= nums[left];
        left++;
      }
      if (cur_product < k) {
        count += right - left + 1;
      }
    }
    return count;
  }
};

/* Runtime: 168 ms, faster than 37.57% of C++ online submissions for Subarray Product Less Than K.
 * Memory Usage: 61.3 MB, less than 19.82% of C++ online submissions for Subarray Product Less Than K.
 */


==> 394-decode-string_2.cpp <==
class Solution {
 public:
  string decodeString(string s) {
    stack<pair<string, int> > st;  // (prev_str, k_count)
    int k = 0;
    string cur_str = "";
    
    for (const auto& c : s) {
      if (c == '[') {
        // starting a new bracket-surronding area:
        // pushing the previous completed string
        // and the count of the starting span k onto stack
        st.push({cur_str, k});  // cur_str becomes prev_str here
        k = 0;
        cur_str = "";
      } else if (c == ']') {
        // the area has ended; pop out the recently-stored pair of
        // prev_str: to be appended;
        // k-count: repeat k times of cur_str and append to prev_str
        auto [prev_str, k_count] = st.top();
        st.pop();
        string to_append = "";
        while (k_count > 0) {
          to_append += cur_str;
          k_count--;
        }
        cur_str = prev_str + to_append;
      } else if (isdigit(c)) {
        k = k * 10 + (c - '0');
      } else {
        cur_str += c;
      }
    }
    
    return cur_str;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
 * Memory Usage: 6.6 MB, less than 37.02% of C++ online submissions for Decode String. 
 */


==> 1472-design-browser-history_1.cpp <==
class BrowserHistory {
 private:
  vector<string> history;
  int ptr;

 public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    ptr = 0;
  }

  void visit(string url) {
    if (ptr != history.size() - 1) {
      history.resize(ptr + 1);
    }
    history.push_back(url);
    ptr++;
  }

  string back(int steps) {
    if (ptr - steps < 0) {
      ptr = 0;
    } else {
      ptr -= steps;
    }
    return history[ptr]; 
  }

  string forward(int steps) {
    if (ptr + steps > history.size() - 1) {
      ptr = history.size() - 1;
    } else {
      ptr += steps;
    }
    return history[ptr];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/* Runtime: 309 ms, faster than 33.49% of C++ online submissions for Design Browser History.
 * Memory Usage: 57.5 MB, less than 79.23% of C++ online submissions for Design Browser History.
 */


==> 430-flatten-a-multilevel-doubly-linked-list_2.cpp <==
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 public:
  Node* flatten(Node* head) {
    Node* dummy_head = new Node();
    stack<Node*> st;
    if (head != nullptr) {
      st.push(head);
    } else {
      return head;
    }
    Node* cur_node = dummy_head;
    while (! st.empty()) {
      Node* top = st.top();
      st.pop();
      cur_node->next = top;
      top->prev = cur_node;
      if (top->next != nullptr) {
        st.push(top->next);
      }
      if (top->child != nullptr) {
        st.push(top->child);
        top->child = nullptr;
      }
      cur_node = cur_node->next;
    }
    cur_node->next = nullptr;
    dummy_head->next->prev = nullptr;
    return dummy_head->next;
  }
};

/* Runtime: 3 ms, faster than 91.79% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 * Memory Usage: 7.4 MB, less than 21.29% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
 */


==> 380-insert-delete-getrandom-o1_1.cpp <==
class RandomizedSet {
 private:
  vector<int> pool;
  unordered_map<int, int> st_map;  // val -> idx to pool vector

 public:
  RandomizedSet() {

  }

  bool insert(int val) {
    if (st_map.find(val) != st_map.end()) {
      return false;
    }
    pool.push_back(val);
    st_map[val] = pool.size() - 1;
    return true;
  }

  bool remove(int val) {
    auto it = st_map.find(val);
    if (it == st_map.end()) {
      return false;
    }
    int idx = it->second;
    st_map.erase(it);
    
    if (idx == pool.size() - 1) {
      pool.pop_back();
      return true;
    }
    int back_val = pool[pool.size() - 1];
    st_map[back_val] = idx;
    pool[idx] = back_val;
    pool.pop_back();
    return true;
  }

  int getRandom() {
    return pool[rand() % pool.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/* Runtime: 475 ms, faster than 35.79% of C++ online submissions for Insert Delete GetRandom O(1).
 * Memory Usage: 97.2 MB, less than 20.95% of C++ online submissions for Insert Delete GetRandom O(1)
 */


==> 1244-design-a-leaderboard_1.cpp <==
class Leaderboard {
 private:
  unordered_map<int, int> player_board;
  multiset<int, greater<int> > scores;

 public:
  Leaderboard() {

  }

  void addScore(int playerId, int score) {
    auto it = scores.find(player_board[playerId]);
    if (it != scores.end()) {
      scores.erase(it);
    }
    player_board[playerId] += score;
    scores.insert(player_board[playerId]);
  }

  int top(int K) {
    int counter = K;
    int sum = 0;
    for (const auto& score : scores) {
      if (counter == 0) break;
      sum += score;
      counter--;
    }
    return sum;
  }

  void reset(int playerId) {
    auto it = scores.find(player_board[playerId]);
    if (it != scores.end()) {
      scores.erase(it);
    }
    player_board[playerId] = 0;
  }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

/* Runtime: 11 ms, faster than 96.61% of C++ online submissions for Design A Leaderboard.
 * Memory Usage: 10.9 MB, less than 66.90% of C++ online submissions for Design A Leaderboard.
 */


==> 253-meeting-rooms_3.cpp <==
class Solution {
 private:
  map<int, int> changes_at_times;  // time -> the positive of negative number of meeting room needs

 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
      changes_at_times[interval[0]]++;
      changes_at_times[interval[1]]--;
    }
    
    int cur_need = 0;
    int cur_max = 0;
    for (const auto& [time, change] : changes_at_times) {
      cur_need += change;
      cur_max = max(cur_max, cur_need);
    }
    
    return cur_max;
  }
};

/* Runtime: 54 ms, faster than 14.35% of C++ online submissions for Meeting Rooms II.
 * Memory Usage: 13.6 MB, less than 20.91% of C++ online submissions for Meeting Rooms II.
 */


==> 155-min-stack_1.cpp <==
class MinStack {
 private:
  stack<int> min_stack;
  stack<int> working_stack;

 public:
  MinStack() {
    
  }

  void push(int val) {
    if (min_stack.empty() || min_stack.top() >= val) {
      min_stack.push(val);
    }
    working_stack.push(val);
  }

  void pop() {
    if (working_stack.empty()) {
      return;
    }
    if (! min_stack.empty() && min_stack.top() == working_stack.top()) {
      min_stack.pop();
    }
    working_stack.pop();
  }

  int top() {
    if (! working_stack.empty()) {
      return working_stack.top();
    }
    return -1;
  }

  int getMin() {
    if (! min_stack.empty()) {
      return min_stack.top();
    }
    return -1;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* Runtime: 25 ms, faster than 87.31% of C++ online submissions for Min Stack.
 * Memory Usage: 16.4 MB, less than 31.20% of C++ online submissions for Min Stack.
 */


==> 1169-invalid-transactions_6.cpp <==
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        trans = [t.split(',') for t in transactions]
        result = []
        for i in range(len(trans)):
            name_i, time_i, amount_i, city_i = trans[i]
            if int(amount_i) > 1000:
                result.append(transactions[i])
                continue
            found = False 
            for j in range(len(trans)):
                if i == j:
                    continue
                name_j, time_j, amount_j, city_j = trans[j]
                if name_i == name_j and abs(int(time_i) - int(time_j)) <= 60 and city_i != city_j:
                    found = True
                    break
            if found:
                result.append(transactions[i])
        return result

"""
Runtime: 88 ms, faster than 84.74% of Python3 online submissions for Invalid Transactions.
Memory Usage: 14.7 MB, less than 39.98% of Python3 online submissions for Invalid Transactions.
"""


==> 322-coin-change_2.cpp <==
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[cur_amount]: the minimal number of coins to sum to cur_amount
    // dp[cur_amount] = min(use the cur_coin, keep it the same)
    // dp[cur_amount] = min(dp[cur_amount], 1 + dp[cur_amount - cur_coin_value]);
    //                                      ^--- one (current) coin
    
    sort(coins.begin(), coins.end());
    // e.g. amount = 7, we need that dp[7] and also the base case dp[0].
    vector<int> dp(amount + 1, amount + 1);
    // Init the base case dp[0]. We need 0 coins to make the amount = 0
    dp[0] = 0;
    for (int amt = 1; amt <= amount; amt++) {
      for (const auto& coin : coins) {
        if (amt - coin < 0) {
          break;
        }
        dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
      }
    }
    
    if (dp[amount] == amount + 1) {
      return -1;
    } else {
      return dp[amount];
    }
  }
};

/* Runtime: 155 ms, faster than 49.95% of C++ online submissions for Coin Change.
 * Memory Usage: 14.4 MB, less than 76.19% of C++ online submissions for Coin Change.
 */


==> 1396-design-underground-system_4.cpp <==
class UndergroundSystem {
 private:
  unordered_map<int, pair<string, int> > check_ins;  // user_id -> (sta_name, time)
  // start_sta -> end_sta -> (trip_cnt, total_trip_duration)
  unordered_map<string, unordered_map<string, pair<int, int> > > trips;

 public:
  UndergroundSystem() {
  }

  void checkIn(int id, string stationName, int t) {
    check_ins[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto check_in_entry = check_ins[id];
    trips[check_in_entry.first][stationName].first++;
    trips[check_in_entry.first][stationName].second += t - check_in_entry.second;
  }

  double getAverageTime(string startStation, string endStation) {
    return double(trips[startStation][endStation].second) / trips[startStation][endStation].first;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

/* Runtime: 188 ms, faster than 80.36% of C++ online submissions for Design Underground System.
 * Memory Usage: 58.1 MB, less than 79.31% of C++ online submissions for Design Underground System.
 */


==> 706-design-hashmap_1.cpp <==
class MyHashMap {
 public:
  vector<vector<pair<int, int> > > hashtable;
  MyHashMap() {
    hashtable = vector<vector<pair<int, int> > >(10000, vector<pair<int, int> >());
  }

  void put(int key, int value) {
    int hash_key = key / 10000;
    for (auto& p : hashtable[hash_key]) {
      if (p.first == key) {
        p.second = value;
        return;
      }
    }
    hashtable[hash_key].push_back(pair<int, int>{key, value});
  }

  int get(int key) {
    int hash_key = key / 10000;
    for (const auto& p : hashtable[hash_key]) {
      if (p.first == key) {
        return p.second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int hash_key = key / 10000;
    for (auto it = hashtable[hash_key].begin(); it != hashtable[hash_key].end(); it++) {
      if ((*it).first == key) {
        hashtable[hash_key].erase(it);
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/* Runtime: 139 ms, faster than 92.56% of C++ online submissions for Design HashMap.
 * Memory Usage: 60.6 MB, less than 57.23% of C++ online submissions for Design HashMap.
 */


==> 314-binary-tree-vertical-order-traversal_2.cpp <==
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 private:
  void inorder_walker(TreeNode* cur_node, map<int, multimap<int, int> >& bins, int cur_offset, int level) {
    if (cur_node == nullptr) {
      return;
    }
    bins[cur_offset].insert(pair<int, int>{level, cur_node->val});
    inorder_walker(cur_node->left, bins, cur_offset - 1, level + 1);
    inorder_walker(cur_node->right, bins, cur_offset + 1, level + 1);
  }

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    // 1. Store values in "bins" by some offsets.
    //    cur_node will be using bins[cur_offset] (root->val will be in bins[0])
    //    and its left child will use bins[cur_offest - 1], and the right child
    //    using bins[cur_offset + 1].
    // 2. Pass the offset to the next level of recursion.
    // 3. From up to down so pre-order traversal is used.
    
    // use an ordered map for easier sorting
    map<int, multimap<int, int> > bins;  // offset -> level -> node value
    inorder_walker(root, bins, 0, 0);
    
    vector<vector<int> > result;
    for (const auto& bin : bins) {
      vector<int> bin_vec;
      for (const auto& elem : bin.second) {
        bin_vec.push_back(elem.second);
      }
      result.push_back(bin_vec);
    }
    return result;
  }
};

/* Runtime: 8 ms, faster than 53.00% of C++ online submissions for Binary Tree Vertical Order Traversal.
 * Memory Usage: 13 MB, less than 16.08% of C++ online submissions for Binary Tree Vertical Order Traversal.
 */


==> 2-add-two-numbers_1.cpp <==
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


==> 42-trapping-rain-water_1.cpp <==
class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int cur_left_tallest = height[left];
    int cur_right_tallest = height[right];
    int trapped_rain = 0;
    
    while (left < right) {
      if (cur_left_tallest <= cur_right_tallest) {
        left++;
        if (cur_left_tallest - height[left] > 0) {
          trapped_rain += cur_left_tallest - height[left];
        } else {
          cur_left_tallest = height[left];
        }
      } else {
        right--;
        if (cur_right_tallest - height[right] > 0) {
          trapped_rain += cur_right_tallest - height[right];
        } else {
          cur_right_tallest = height[right];
        }
      }
    }
    return trapped_rain;
  }
};

/* Runtime: 28 ms, faster than 54.92% of C++ online submissions for Trapping Rain Water.
 * Memory Usage: 19.8 MB, less than 81.97% of C++ online submissions for Trapping Rain Water.
 */


==> 128-longest-consecutive-sequence_2.cpp <==
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());
    unordered_set<int> seen;
    int cur_max = 0;
    
    for (const auto& num : nums) {
      if (seen.count(num) > 0) {
        continue;
      }
      int cur_cnt = 0;
      seen.insert(num);
      cur_cnt++;
      for (int i = 1; num_set.count(num + i) > 0; i++) {
        seen.insert(num + i);
        cur_cnt++;
      }
      for (int i = -1; num_set.count(num + i) > 0; i--) {
        seen.insert(num + i);
        cur_cnt++;
      }
      if (cur_cnt > cur_max) {
        cur_max = cur_cnt;
      }
    }
    
    return cur_max;
  }
};

/* Runtime: 439 ms, faster than 42.24% of C++ online submissions for Longest Consecutive Sequence.
 * Memory Usage: 61.8 MB, less than 5.05% of C++ online submissions for Longest Consecutive Sequence.
 */


==> 1347-minimum-number-of-steps-to-make-two-strings-anagram_2.cpp <==
class Solution {
 public:
  int minSteps(string s, string t) {
    // count the frequencies of each characters in the two strings
    // since they are both consisting of only lowercase English letters
    // we can use vectors
    vector<int> freqs(26, 0);
    vector<int> freqt(26, 0);
    for (const auto& c : s) {
      freqs[c - 'a']++;
    }
    for (const auto& c : t) {
      freqt[c - 'a']++;
    }
    
    // how many ops?
    int diff = 0;
    for (int i = 0; i < freqs.size(); i++) {
      diff += abs(freqs[i] - freqt[i]);
    }
    
    return diff / 2;
  }
};

/* Runtime: 110 ms, faster than 50.60% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 * Memory Usage: 16.6 MB, less than 38.38% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
 */


==> 399-evaluate-division_2.cpp <==
class Solution {
 private:
  double worker(unordered_map<string, vector<pair<string, double> > >& table,
                unordered_set<string>& seen, string cur_stop, string target, double cur_product) {
    if (seen.count(cur_stop) > 0) {
      return -1.0;
    }
    seen.insert(cur_stop);
    if (table[cur_stop].size() == 0) {
      return -1.0;
    }
    if (cur_stop == target) {
      return cur_product;
    }
    for (const auto& p : table[cur_stop]) {
      double result = worker(table, seen, p.first, target, cur_product * p.second);
      if (result != -1.0) {
        return result;
      }
    }
    return -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    // build the dict
    unordered_map<string, vector<pair<string, double> > > table;
    for (int i = 0; i < equations.size(); i++) {
      table[equations[i][0]].push_back(pair<string, double>{equations[i][1], values[i]});
      table[equations[i][1]].push_back(pair<string, double>{equations[i][0], 1.0 / values[i]});
    }
    
    vector<double> result;
    for (const auto& q : queries) {
      unordered_set<string> seen;
      double res = worker(table, seen, q[0], q[1], 1.0);
      result.push_back(res);
    }
    
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.
 * Memory Usage: 8.3 MB, less than 52.83% of C++ online submissions for Evaluate Division.
 */


==> 13-roman-to-integer_1.cpp <==
class Solution {
 public:
  int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'I') {
        if (i + 1 < s.size() && s[i + 1] == 'V') {
          result += 4;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'X') {
          result += 9;
          i++;
        } else {
          result += 1;
        }
      } else if (s[i] == 'X') {
        if (i + 1 < s.size() && s[i + 1] == 'L') {
          result += 40;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'C') {
          result += 90;
          i++;
        } else {
          result += 10;
        }
      } else if (s[i] == 'C') {
        if (i + 1 < s.size() && s[i + 1] == 'D') {
          result += 400;
          i++;
        } else if (i + 1 < s.size() && s[i + 1] == 'M') {
          result += 900;
          i++;
        } else {
          result += 100;
        }
      } else if (s[i] == 'V') {
        result += 5;
      } else if (s[i] == 'L') {
        result += 50;
      } else if (s[i] == 'D') {
        result += 500;
      } else {
        result += 1000;
      }
    }
    return result;
  }
};

/* Runtime: 19 ms, faster than 55.18% of C++ online submissions for Roman to Integer.
 * Memory Usage: 6 MB, less than 69.50% of C++ online submissions for Roman to Integer.
 */


==> 200-number-of-islands_2.cpp <==
class Solution {
 private:
  void dfs(vector<vector<char> >& grid, int row, int col) {
    grid[row][col] = '0';
    for (int i = row - 1; i <= row + 1; i++) {
      if (i < 0 || i >= grid.size() || grid[i][col] == '0') {
        continue;
      } else {
        dfs(grid, i, col);
      }
    }
    for (int j = col - 1; j <= col + 1; j++) {
      if (j < 0 || j >= grid[0].size() || grid[row][j] == '0') {
        continue;
      } else {
        dfs(grid, row, j);
      }
    }
  }
 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};

/* Runtime: 37 ms, faster than 91.90% of C++ online submissions for Number of Islands.
 * Memory Usage: 12.3 MB, less than 82.28% of C++ online submissions for Number of Islands.
 */


==> 225-implement-stack-using-queues_4.cpp <==
class MyStack {
 private:
  queue<int> working;
  queue<int> tmp;

 public:
  MyStack() {

  }

  void push(int x) {
    working.push(x);
  }

  int pop() {
    while (working.size() > 1) {
      tmp.push(working.front());
      working.pop();
    }
    int popped = working.front();
    working.pop();
    
    swap(working, tmp);
    
    return popped;
  }

  int top() {
    int popped = pop();
    push(popped);
    return popped;
  }

  bool empty() {
    return working.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/* Runtime: 4 ms, faster than 28.30% of C++ online submissions for Implement Stack using Queues.
 * Memory Usage: 7 MB, less than 25.83% of C++ online submissions for Implement Stack using Queues.
 */


==> 232-implement-queue-using-stacks_2.cpp <==
class MyQueue {
 private:
  stack<int> working;
  stack<int> tmp;

 public:
  MyQueue() {

  }

  void push(int x) {
    working.push(x);
  }

  int pop() {
    while (! working.empty()) {
      tmp.push(working.top());
      working.pop();
    }
    int peeked = tmp.top();
    tmp.pop();
    while (! tmp.empty()) {
      working.push(tmp.top());
      tmp.pop();
    }
    return peeked;
  }

  int peek() {
    while (! working.empty()) {
      tmp.push(working.top());
      working.pop();
    }
    int peeked = tmp.top();
    while (! tmp.empty()) {
      working.push(tmp.top());
      tmp.pop();
    }
    return peeked;
  }

  bool empty() {
    return working.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
 * Memory Usage: 6.9 MB, less than 89.61% of C++ online submissions for Implement Queue using Stacks.
 */


==> 1047-remove-all-adjacent-duplicates-in-string_4.cpp <==
class Solution {
 public:
  string removeDuplicates(string s) {
    string result = "";
    for (const auto& c : s) {
      if (result.size() == 0) {
        result.push_back(c);
      } else if (result.back() == c) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

/* Runtime: 55 ms, faster than 36.84% of C++ online submissions for Remove All Adjacent Duplicates In String.
 * Memory Usage: 10.8 MB, less than 72.76% of C++ online submissions for Remove All Adjacent Duplicates In String.
 */


==> 239-sliding-window-maximum_6.cpp <==
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int> > window;
    vector<int> result;

    // loop the nums
    for (int i = 0; i < nums.size(); i++) {
      // to implement a structure that
      // cur_max = dq.front();
      // dq.front() gets popped out if it's out of the window
      // to do this, we need to store the indices
      
      // remove "expired" element
      while (! window.empty() && window.front().first <= i - k) {
        window.pop_front();
      }
      
      // if the new element is larger than the back of the window, pop the back
      // since it's not possible to be a max
      while (! window.empty() && nums[i] >= window.back().second) {
        window.pop_back();
      }
      window.push_back(pair<int, int>{i, nums[i]});
      
      // if i >= k - 1 (i >= 2 if k = 3: idx 0, 1, 2)
      // we can start getting the result at the front our dq
      if (i >= k - 1) {
        result.push_back(window.front().second);
      }
    }
    
    return result;
  }
};

/* Runtime: 319 ms, faster than 91.18% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 137 MB, less than 35.65% of C++ online submissions for Sliding Window Maximum.
 */


==> 20-valid-parentheses_3.cpp <==
class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 2 != 0) {
      return false;
    }
    stack<char> char_to_pair;
    for (const auto& c : s) {
      if (! char_to_pair.empty() && char_to_pair.top() == c) {
        char_to_pair.pop();
      } else if (c == '(') {
        char_to_pair.push(')');
      } else if (c == '[') {
        char_to_pair.push(']');
      } else if (c == '{') {
        char_to_pair.push('}');
      } else {
        return false;
      }
    }
    if (char_to_pair.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

/* Runtime: 7 ms, faster than 9.28% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 6.3 MB, less than 79.92% of C++ online submissions for Valid Parentheses.
 */



==> 665-non-decreasing-array_2.cpp <==
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    bool seen_anomaly = false;
    if (nums.size() == 1) {
      return true;
    }
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        if (seen_anomaly) {
          return false;
        }
        seen_anomaly = true;
        if (i == 1 || nums[i - 2] <= nums[i]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
      }
    }
    return true;
  }
};

/* Runtime: 80 ms, faster than 5.12% of C++ online submissions for Non-decreasing Array.
 * Memory Usage: 27.1 MB, less than 54.22% of C++ online submissions for Non-decreasing Array.
 */

