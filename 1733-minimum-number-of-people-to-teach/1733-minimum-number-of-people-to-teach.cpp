class Solution {

public:
    bool hasLang(vector<int>& langlist, int lang){
        for(auto& l : langlist) {
            if (l == lang) return true;
        }
        return false;
    }
    
    bool canComm(int u, int v, int n, vector<vector<bool>>& langs) {
        for (int l=0; l<n; l++) {
            if (langs[u][l] && langs[v][l]) return true;
        }
        return false;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int persons = languages.size();
        //use to check a person know a langauge or not
        vector<vector<bool>> langs(persons, vector<bool>(n, false));
        for (int p=0; p<persons; p++) {
            for(int l=0; l<languages[p].size(); l++) {
                langs[p][languages[p][l]-1] = true;
            }
        } 
        
        int result = persons;
        vector<vector<bool>> langToTeach(n, vector<bool>(persons, false));
        for (int l=0; l <n; l++) {
            int cnt = 0;
            vector<bool> teach(persons, false);
            for (auto& fs : friendships) {
                int u = fs[0] - 1;
                int v = fs[1] - 1;

                if (canComm(u, v, n, langs)) continue;

                if (langs[u][l]==false && teach[u]==false) {
                    teach[u] = true; cnt++;
                }
                if (langs[v][l]==false && teach[v]==false) {
                    teach[v] = true; cnt++;
                }
            }
            result = min(result, cnt);
        }
        
        return result;
    }
};