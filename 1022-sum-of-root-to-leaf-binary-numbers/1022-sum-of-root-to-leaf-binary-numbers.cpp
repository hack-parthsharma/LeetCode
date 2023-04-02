class Solution {
    int ans = 0;
    void preorder(TreeNode *root, int path) {
        if (!root) return;
        path = (path << 1) + root->val;
        if (!root->left && !root->right) {
            ans += path;
            return;
        }
        preorder(root->left, path);
        preorder(root->right, path);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
};