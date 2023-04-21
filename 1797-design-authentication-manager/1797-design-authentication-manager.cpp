class AuthenticationManager {
private: 
    int ttl;
    set<pair<int, string>> time_set;
    unordered_map<string, int> token_map;
public:
    AuthenticationManager(int timeToLive):ttl(timeToLive) { }
    
    void generate(string tokenId, int currentTime) {
        token_map[tokenId] = currentTime;
        time_set.insert({currentTime, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        //if the token is not found, or the token is expired
        if (token_map.find(tokenId) == token_map.end() ||
            token_map[tokenId] + ttl <= currentTime ) {
            return;
        }
        time_set.erase({token_map[tokenId], tokenId});
        time_set.insert({currentTime, tokenId});
        token_map[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        return clean(currentTime - ttl);
    }
    
    int clean(int expired) {

        auto it = time_set.begin();
        while(!time_set.empty() && it->first <= expired) {
            token_map.erase(it->second);
            time_set.erase(it);
            it = time_set.begin();
        }
        return time_set.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */