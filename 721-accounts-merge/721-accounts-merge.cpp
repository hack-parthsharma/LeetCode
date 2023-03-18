class Solution {
public:
    // We can orginze all relevant emails to a chain,
    // then we can use Union Find algorithm
    // Besides, we also need to map the relationship between name and email.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emails_id; //using email ID for union find
        unordered_map<int, int> emails_chains; // email chains
        unordered_map<int, string> names; // email id & name

        //initialization & join
        for(int i = 0 ; i<accounts.size();i++) {

            // using the account index as the emails group ID,
            // this could simplify the emails chain.
            emails_chains[i] = i;

            auto& account = accounts[i];
            auto& name = account[0];
            for (int j=1; j<account.size(); j++) {
                auto& email = account[j];
                if ( emails_id.find(email) == emails_id.end() ) {
                    emails_id[email] = i;
                    names[i] = name;
                }else {
                    join( emails_chains, i, emails_id[email] );
                }

            }
        }

        //reform the emails
        unordered_map<int, set<string>> res;
        for(int i=0; i<accounts.size(); i++) {
            int idx = find(emails_chains, i);
            res[idx].insert(accounts[i].begin()+1, accounts[i].end());
        }


        //output the result
        vector<vector<string>> result;
        for (auto pair : res) {
            vector<string> emails( pair.second.begin(), pair.second.end() );
            emails.insert(emails.begin(), names[pair.first]);
            result.push_back(emails);
        }
        return result;
    }

    int find(unordered_map<int, int>& emails_chains, int id) {
        while( id != emails_chains[id] ){
            id = emails_chains[id];
        }
        return id;
    }

    bool join(unordered_map<int, int>& emails_chains, int id1, int id2) {
        int e1 = find(emails_chains, id1);
        int e2 = find(emails_chains, id2);
        if ( e1 != e2 )  emails_chains[e1] = e2;
        return e1 == e2;
    }
};