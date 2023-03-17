class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int dx=0, dy=0;
        TreeNode *px=root, *py=root;
        dx = DepthAndParent(root, px, 0, x);
        dy = DepthAndParent(root, py, 0, y);
        if (dx && dy){
            return (dx == dy && px != py);
        }

        return false;

    }

    int DepthAndParent(TreeNode* root, TreeNode*& parent, int depth, int x) {
        if (!root) return 0;
        if ( root->val == x) return depth;

        int d=0;
        parent = root;
        if  ( ( d = DepthAndParent(root->left, parent, depth+1, x)) > 0 ) return d;

        parent = root;
        if ( ( d = DepthAndParent(root->right, parent, depth+1, x)) > 0 ) return d;
        return 0;
    }
};