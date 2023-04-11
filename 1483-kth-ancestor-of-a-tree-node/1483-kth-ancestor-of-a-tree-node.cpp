class TreeAncestor {
    vector<int> nodeToId, idToNode, idToLevel;
    vector<vector<int>> tree, G;
    void preorder(int node, int &id, int level) {
        if (level >= tree.size()) tree.emplace_back();
        tree[level].push_back(id);
        nodeToId[node] = id;
        idToNode[id] = node;
        idToLevel[id] = level;
        ++id;
        for (int child : G[node]) preorder(child, id, level + 1);
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        nodeToId.assign(n, 0);
        idToNode.assign(n, 0);
        idToLevel.assign(n, 0);
        G.assign(n, {});
        for (int i = 1; i < n; ++i) G[parent[i]].push_back(i);
        int id = 0;
        preorder(0, id, 0);
    }
    int getKthAncestor(int node, int k) {
        int id = nodeToId[node], level = idToLevel[id] - k;
        if (level < 0) return -1;
        return idToNode[*(upper_bound(begin(tree[level]), end(tree[level]), id) - 1)];
    }
};
