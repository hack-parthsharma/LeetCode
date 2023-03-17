class Solution {
public:

    TreeNode* recoverFromPreorder(string S) {
        vector<int>values,depth;
        int cur_val = 0 , cur_depth = 0;
        bool dash = false;
        for(char s : S){
            if(s == '-'){
                if(!dash){
                    values.push_back(cur_val);
                    depth.push_back(cur_depth);
                    cur_depth = 0;
                    cur_val = 0;
                }
                dash = true;
                cur_depth++;
            }
            else{
                dash = false;
                cur_val *= 10;
                cur_val += s-'0';
            }
        }
        values.push_back(cur_val);
        depth.push_back(cur_depth);

        unordered_map<TreeNode*,int>depths;


        int ptr = 1;
        TreeNode *root = new TreeNode(values[0]);
        depths[root] = 0;
        stack<TreeNode*>st;
        st.push(root);

        while(ptr < (int)values.size()){
            TreeNode *cur = st.top();
            if(depth[ptr] == depths[cur]+1 && (cur->left == NULL || cur->right == NULL)){
                TreeNode *t = new TreeNode(values[ptr++]);
                depths[t] = depths[cur]+1;
                if(cur->left == NULL){
                    cur->left = t;
                }
                else{
                    cur->right = t;
                }
                st.push(t);
            }
            else{
                st.pop();
            }
        }
        return root;

    }
};