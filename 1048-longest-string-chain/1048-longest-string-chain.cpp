class Solution {
private:
    int dfs(string s, unordered_set<string>& cache, unordered_map<string, int>& memo){
        if(memo.find(s)!=memo.end()) return memo[s];
        
        int maxLen=1;
        for(int i=0;i<s.length();i++){
            string newStr = s.substr(0, i) + s.substr(i+1);
            if(cache.find(newStr)!=cache.end()) {
                int len = (1 + dfs(newStr, cache, memo));
                maxLen = max(maxLen, len);
            }
        }
        
        return memo[s] = maxLen;
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> cache;
        for(auto word:words) cache.insert(word);
        unordered_map<string, int> memo;
        
        int ans=INT_MIN;
        for(auto word:words){
            ans = max(ans, dfs(word, cache, memo));
        }
        
        return ans;
    }
};