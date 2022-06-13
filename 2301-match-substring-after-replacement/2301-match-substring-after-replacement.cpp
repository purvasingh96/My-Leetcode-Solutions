class Solution {
vector<int> compute_lps(string &s, unordered_map<char, unordered_set<char>> &m) {
    vector<int> lps(s.size());
    for (int i = 1, j = 0; i < s.size(); ++i) {
        while (j && (s[i] != s[j] && m[s[i]].count(s[j]) == 0 && m[s[j]].count(s[i]) == 0))
            j = max(0, lps[j] - 1);
        j += s[i] == s[j] || m[s[i]].count(s[j]) || m[s[j]].count(s[i]);
        lps[i] = j;
    }
    return lps;
}

vector<int> generateLPS(string sub, map<char, unordered_set<char>>& m){
    int n = sub.length();
    int j=0;
    vector<int> lps(n, 0);
    
    for(int i=1;i<n;){
        
        if(sub[i] == sub[j] || m[sub[i]].count(sub[j]) || m[sub[j]].count(sub[i])){
            
            lps[i]=j+1;
            i+=1;
            j+=1;
            
        } else{
            
            if(j>0){
                j = lps[i-1];
            }
            else {
                i+=1;
            }
        }
        
    }
    return lps;
}
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char, unordered_set<char>> m;
        for(auto c:mappings){
            m[c[0]].insert(c[1]);
        }
        auto lps  = compute_lps(sub, m);
        
        int j=0;
        for(int i=0;i<s.length();){
            
            if(s[i] == sub[j] || m[sub[j]].count(s[i])){
                i+=1;
                j+=1;
            } else{
                if(j>0){
                    j= lps[j-1];
                } else{
                    i+=1;
                }
            }
            
            if(j==sub.length()){
                return true;
            }
            
        }
        
        
        return false;
    }
};