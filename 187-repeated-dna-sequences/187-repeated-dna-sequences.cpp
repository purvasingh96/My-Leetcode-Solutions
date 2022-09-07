class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int base = 31, mod=1e9+7;
        int k=10, n = s.length();
        long long h=1;
        unordered_map<long long, string> seen;
        unordered_set<string> res;
        
        for(int i=0;i<k-1;i++){
            h *= base;
            h = h%mod;
        }
        
        long long sHash=0;
        for(int i=0;i<k;i++){
            sHash = (sHash*base + s[i]);
            sHash %=mod;
        }
        
        //seen[sHash] = s.substr(0, k);
        
        for(int i=0;i<=(n-k);i++){
            if(seen.find(sHash)==seen.end()){
                seen[sHash] = s.substr(i, k);
            } else {
                if(s.substr(i, k) == seen[sHash]) {
                    res.insert(seen[sHash]);
                }
            }
            
            if(i<(n-k)){
                sHash = ((sHash - h*s[i])*base +s[i+k])%mod;
                if(sHash <0) sHash+=mod;
            }
        }
        
        vector<string> ans(res.begin(), res.end());
        
        return ans;
        
    }
};