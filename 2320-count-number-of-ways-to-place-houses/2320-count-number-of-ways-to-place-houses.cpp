class Solution {
public:
    int countHousePlacements(int n) {
      long x = 1, y = 1, z=0;
        long mod = 1e9+7;
        
        
        for(int i=1;i<=n;i++){
             z = (x+y)%mod;
            x=y;
            y=z;
            
        }
        
        long long ans = (z%mod * z%mod);
        int res = ans%mod;
        return res;
    }
};