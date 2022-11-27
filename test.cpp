#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "ctype.h"
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  struct prop_of_tree {
    int height;
    bool ifbalanced;
    prop_of_tree() : height(0), ifbalanced(true) {}
  };

  bool isBalanced(TreeNode *root) {
    if (!root) return true;
    return check_tree(root).ifbalanced;
  }
  prop_of_tree check_tree(TreeNode *root) {
    prop_of_tree result;
    if (!root) return result;
    prop_of_tree leftsubtree = check_tree(root->left);
    prop_of_tree rightsubtree = check_tree(root->right);
    result.height = max(leftsubtree.height, rightsubtree.height) + 1;
    result.ifbalanced = leftsubtree.ifbalanced && rightsubtree.ifbalanced &&
                        (abs(leftsubtree.height - rightsubtree.height) <= 1);
    return result;
  }
};

void test(void) {}