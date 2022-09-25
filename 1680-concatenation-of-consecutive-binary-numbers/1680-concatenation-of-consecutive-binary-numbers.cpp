class Solution {
 
public:
    int concatenatedBinary(int n) {
        int mod=1e9+7, curlen=0;
        long long prev=0;
        
        
        for(int i=1;i<=n;i++){
            
            if((i & (i-1)) == 0) curlen+=1;
            
            prev = (prev << curlen)%mod;
            
            prev%=mod;
            prev += i;
        }
        
        return prev;
    }
};