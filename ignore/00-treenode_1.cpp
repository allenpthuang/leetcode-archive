#include <iostream>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

int main() {
  TreeNode node(5566);
  TreeNode node_2(5567);
  TreeNode* node_3 = new TreeNode(5568);
  TreeNode* node_4 = new TreeNode(5569);
  node.left = &node_2;
  node.right = node_3;
  node_3->right = node_4;
  cout << node.left->val << endl; // 5567
  cout << node.right->val << endl; // 5568
  cout << node_4->val << endl; // 5569
  cout << node_3->right->val << endl; // 5569
  cout << node_2.val << endl; // 5567
  return 0;
}
