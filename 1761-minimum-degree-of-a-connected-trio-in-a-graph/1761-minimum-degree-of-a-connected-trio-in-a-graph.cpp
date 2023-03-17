class Solution {
private:
    vector<vector<bool>>* edge_matrix;
    vector<int>* node_edge_num;
    
    bool has_edge(int x, int y) {
        return (*edge_matrix)[x][y];
    }
    
    int node_edges(int x){
        return (*node_edge_num)[x];
    }
    
    int degree(int x, int y, int z) {
        if (has_edge(x,y) && has_edge(y,z) && has_edge(x,z)) {
            return node_edges(x) +  node_edges(y) +  node_edges(z) - 6; 
        }
        return -1;
    }
public:
   
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> edge_matrix(n+1, vector<bool>(n+1, false));
        vector<int> node_edge_num(n+1, 0);
        
        this->edge_matrix = &edge_matrix;
        this->node_edge_num = &node_edge_num;
        
        for (auto& edge : edges) {
            edge_matrix[edge[0]][edge[1]] = true;
            edge_matrix[edge[1]][edge[0]] = true;
            node_edge_num[edge[0]]++;
            node_edge_num[edge[1]]++;
        }
        
        int result = -1;
        for(int i=1; i<=n; i++) {
            if (node_edge_num[i] < 2) continue;
            for(int j=i+1; j<=n; j++) {
                if (!has_edge(i, j)) continue;
                for(int k=j+1; k<=n; k++) {
                    if (!has_edge(j, k)) continue;
                    int d = degree(i, j, k);
                    if ( d >= 0 ) {
                        result = result < 0 ? d : min(result, d);
                    }
                }
            }
        }
        return result;
    }
};