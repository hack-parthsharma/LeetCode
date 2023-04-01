class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return helper(root, root->val);
    }
    bool helper(TreeNode* node, int val) {
        if (!node) return true;
        if (node->val != val) return false;
        return helper(node->left, val) && helper(node->right, val);
    }
};

