class Solution {
private:
    int diameter;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        maxDepth(root);
        return diameter;
    }
};