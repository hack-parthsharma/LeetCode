class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n = row.size();
        int m = col.size();
        if(n==0 ||m==0)
            return {};
        vector<vector<int>> res(n,vector<int>(m,0));
        priority_queue<pair<int,int>> p,q;
        for(int i=0;i<n;i++){
            p.push({row[i],i});
        }
        for(int j=0;j<m;j++){
            q.push({col[j],j});
        }

        while(!q.empty() && !p.empty()){
            auto a = p.top();
            auto b = q.top();
            p.pop();
            q.pop();
            int t = min(a.first,b.first);
            res[a.second][b.second]=t;
            a.first-=t;
            b.first-=t;
            if(a.first>0)
                p.push(a);
            if(b.first>0)
                q.push(b);
        }
        return res;
    }
};