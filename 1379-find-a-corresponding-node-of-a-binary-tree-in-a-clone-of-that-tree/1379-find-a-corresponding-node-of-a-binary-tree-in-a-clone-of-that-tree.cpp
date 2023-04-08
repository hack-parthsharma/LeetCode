class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return NULL;
        if (original == target) return cloned;
        auto ans = getTargetCopy(original->left, cloned->left, target);
        return ans ? ans : getTargetCopy(original->right, cloned->right, target);
    }
};