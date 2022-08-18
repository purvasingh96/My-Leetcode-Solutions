class Solution {
// stoi(binaryNumber, 0, 2);
public:
    bool hasAllCodes(string s, int k) {
        int sz = pow(2, k);
        set<long long> res;
        int n = s.length();
        
        long long h = 1;
        int base = 2, mod=1e9+7;
        
        for(int i=0;i<k-1;i++){
            h = h*base;
            h=h%mod;
        }
    
        
        long long sHash = stoi(s.substr(0, k), 0, 2);
        
        for(int i=0;i<=(n - k);i++){
            if(sHash < sz) res.insert(sHash);
            
            if(i<(n-k)){
                sHash = ((sHash - h*(s[i]-'0'))*base)%mod + (s[i+k]-'0');
                if(sHash < 0) sHash += mod;
            }  
        }
        
        return res.size() == sz;
    }
};