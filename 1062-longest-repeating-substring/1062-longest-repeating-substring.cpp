class Solution {
private:
    bool feasible(string s, int k){
        int base=31, mod=1e9+7, n = s.length();
        long long h=1, sHash=0;
        unordered_map<long long, string> seen;
        
        for(int i=0;i<k-1;i++){
            h = h*base;
            h = h%mod;
        }
        
        for(int i=0;i<k;i++){
            sHash = (sHash*base + s[i])%mod;
        }
        
        for(int i=0;i<=(n-k);i++){
            if(seen.find(sHash) == seen.end()){
                seen[sHash] = s.substr(i, k);
                
            } else {
                if(seen[sHash] == s.substr(i, k)) return true;
            }
            
            if(i<(n-k)){
                sHash = ((sHash - h*s[i])*base + s[i+k])%mod;
                if(sHash <0) sHash += mod;
            }
            
        }
        
        return false;
    }
public:
    int longestRepeatingSubstring(string s) {
        
        int left=0, right=s.length()-1;
        int ans=0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            bool f= feasible(s, mid);
            //cout<<"mid: "<<mid<<" feasible: "<<f<<"\n";
            if(f) {
                ans=mid;
                left = mid+1;
            } else{
                right=mid-1;
            }
            
        }
        
        return ans;
        
    }
};