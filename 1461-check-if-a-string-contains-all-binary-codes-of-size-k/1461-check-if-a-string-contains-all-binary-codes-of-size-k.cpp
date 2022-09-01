class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int target = pow(2,k);
        set<long long> st;
        
        long long h = 1;
        int base =2, mod = 1e9, n =s.length();
        
        for(int i=0;i<k-1;i++){
            h = h*base;
            h=h%mod;
        }
        
        long long sHash=0;
        
        sHash = stoi(s.substr(0, k), 0, 2);
        
        for(int i=0;i<=(n-k);i++){
            if(sHash < target){
                st.insert(sHash);
            }
            
            if(i<(n-k)){
                sHash = ((sHash - h*(s[i]-'0'))*base) + (s[i+k]-'0');
            }
        }
        
        return st.size() == target;
        
    }
};