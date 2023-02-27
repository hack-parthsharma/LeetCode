const int COLOR_CNT = 26;

class Node {
public:
    Node(char c) {
        incomming = 0;
        color = c;
        processed = false;
        memset(colors, 0, sizeof(colors));
    }
    void AddMyColor() { colors[color]++; }
    void Processed() { processed = true; }
    bool isProcessed() { return processed; }
    void AddIncomming(int n=1) { incomming += n;}
    int Incomming() {return incomming;}
    void AddChildNode(int n) { children.push_back(n); }
    vector<int>& Children() { return children; }
    int ChildrenCount() { return children.size(); }
    int* Colors() {return colors;}
    int MaxColorValue() {
        int m = -1;
        for(auto c: colors) {
            m = max(m, c);
        }
        return m;
    }
    void MergeChildColors(Node& child){
        int* c = child.Colors();
        for(int i=0; i<COLOR_CNT; i++) {
            colors[i] = max(colors[i], c[i]);
        }
    }

private:
    int incomming;          // incomming connection
    char color;             // node's color
    bool processed;         // if the node has been processed
    int colors[COLOR_CNT];  // the colors count stastices 
    vector<int> children;   // children nodes
};


class Solution {
private:
    void print(vector<int>& v) {
        cout << "[";
        int i = 0;
        for(; i<v.size()-1; i++) {
            cout << v[i] << ",";
        }
        cout << v[i] << "]" << endl;
    }
private:
    int nodes_cnt;
    vector<Node> nodes;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        nodes_cnt = colors.size() ;
        for(int i=0; i<nodes_cnt; i++) {
            Node n( colors[i]-'a');
            nodes.push_back(n);
        }
        for(auto& e : edges) {
            nodes[e[0]].AddChildNode(e[1]);
            nodes[e[1]].AddIncomming();
        }
        
         vector<bool> visited(nodes_cnt, false);
        
        // We can do toplogical sort
        // 
        //vector<int> topSort;
        //for(int id=0; id <nodes_cnt; id++){
        //    auto& n = nodes[id];
        //    topologicalSort(id, topSort, visited);
        //}
        //print(topSort);
        
        int m = -1;
        for (int i=0; i<nodes_cnt; i++) {
            //int id = topSort[i];
            int id = i;
            auto& n = nodes[id];
            
            //using to check cycle.
            std::fill(visited.begin(), visited.end(), false);
            
            bool succ = travel(id, visited);
            if (!succ) return -1;
           
            m = max(m, nodes[id].MaxColorValue());
        }
        return m;
    }
    
    void topologicalSort(int i, vector<int>& topSort, vector<bool>& visited) {
        if (visited[i]) return;
        visited[i] = true;
        for(auto& id : nodes[i].Children()) {
            if (!visited[id]) {
                topologicalSort(id, topSort, visited);
            }
        }
        topSort.push_back(i);
    }
    
    //return true if it is successful
    //return false if there is an error  - has cycle
    bool travel(int i, vector<bool>& visited ) {
        //this node has been processed already
        if (nodes[i].isProcessed()) return true;
        
        //cycled 
        if (visited[i]) return false;
        visited[i] = true;
        
        // leaf node
        if (nodes[i].ChildrenCount() <= 0 ) {
            nodes[i].AddMyColor();
            nodes[i].Processed();
            return true;
        }
      
        for(auto& n : nodes[i].Children() ) {
            bool succ = travel(n, visited);
            if (!succ) return false;
            nodes[i].MergeChildColors( nodes[n] );
        }
        
        nodes[i].AddMyColor();
        nodes[i].Processed();

        //cout << "["<< i << "]: " ;
        //for(int k=0; k<26; k++) {
        //    cout << nodes[i].colors[k] << " ";
        //}
        //cout << endl;
        
        return true;
    }
};
