/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> v;

  void dfs(Node* root, int level) {
    if (root == nullptr) return;
    if (v.size() < level) {
      vector<int> vv;
      this->v.push_back(vv);
    }
    this->v[level - 1].push_back(root->val);
    for (auto i: root->children) {
      dfs(i, level + 1);
    }
  }

  vector<vector<int>> levelOrder(Node* root) {
    dfs(root, 1);
    return v;
  }
};
