class Solution {
private:
    int rollingHash(string s, int k, unordered_map<long long, int>& m){
        int base=131, mod=1e9, n = s.length();
        long long h=1;
        long long sHash=0;
        
        for(int i=0;i<k-1;i++){
            h= h*base;
            h=h%mod;
        }
        
        for(int i=0;i<k;i++){
            sHash = (sHash*base + s[i])%mod;
        }
        
        for(int i=0;i<=(n-k);i++){
            //if(k==3) cout<<s.substr(i, k)<<" "<<sHash<<"\n";
            
            if(m.find(sHash)!=m.end()){
                int idx = m[sHash];
                if(s.substr(idx, k) == s.substr(i, k)){
                    return i;
                }
            }
            else {
                m[sHash] = i;
            }
            
            
            
            if(i<(n-k)){
                sHash = (((sHash - h*s[i])*base) + s[i+k])%mod;
                if(sHash<0) sHash += mod;
            }
            
        }
        
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        unordered_map<long long, int> m;
        
        int left=1, right=n;
        string ans="";
        int max_len = 0;
        
        while(left<right) {
            int mid = left + (right-left)/2;
            int res = rollingHash(s, mid, m);
            if(res!=-1){
                left=mid+1;
            } else right=mid;
        }
        m.clear();
        int idx = rollingHash(s, left-1, m);
        
        return idx==-1?"":s.substr(idx, left-1);
    }
};