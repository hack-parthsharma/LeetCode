class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    //
    // if a node has 0 coin, which means one move from its parent.
    //               1 coin, which means zero move from its parent.
    //               N coins, which means N-1 moves to its parent.
    //
    // So, we can simply know, the movement = coins -1.
    // - negative number means the the coins needs be moved in.
    // - positive number means the the coins nees be moved out.
    //
    // A node needs to consider the movement requests from both its left side and right side.
    // and need to calculate the coins after left and right movement.
    //
    // So, the node coins  = my conins - the coins move out + the coins move in.
    //
    // Then we can have to code as below.
    //
    int dfs(TreeNode* root, int& result) {
        if (root == NULL) return 0;

        int left_move = dfs(root->left, result);
        int right_move = dfs(root->right, result);
        result += (abs(left_move) + abs(right_move));

        // the coin after movement: coins = root->val +left_move + right_move
        // the movement needs:  movement = coins - 1
        return root->val + left_move + right_move - 1;
    }
};