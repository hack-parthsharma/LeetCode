class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    
    TreeNode* const right = root->right;  

    root->left = nullptr;
    root->right = left;

    TreeNode* rightmost = root;
    while (rightmost->right)
      rightmost = rightmost->right;
    rightmost->right = right;
  }
};
