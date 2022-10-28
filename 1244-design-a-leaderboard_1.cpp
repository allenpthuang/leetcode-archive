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

