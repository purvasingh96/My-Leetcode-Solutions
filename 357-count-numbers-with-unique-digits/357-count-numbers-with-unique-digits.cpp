class Solution {
private:
    
    int dfs(string& s, int pos, int tight, int mask, vector<vector<vector<int>>>& dp){
        if(pos==s.length()){
            return mask!=0;
        }
        
        if(dp[pos][tight][mask]!=-1) return dp[pos][tight][mask];
        
        int ans=0;
        
        if(tight == 1){
            
            for(int i=0;i<=s[pos]-'0';i++){
                
                if(mask & 1<<i) continue;
                
                int new_mask = (mask == 0 && i==0) ? mask : (mask | 1<<i);
                
                if(i==s[pos]-'0') {
                    ans += dfs(s, pos+1, 1, new_mask, dp);
                } else {
                    ans += dfs(s, pos+1, 0, new_mask, dp);
                }
                
            }
            
        } else {
            
            for(int i=0;i<10;i++){
                if(mask & (1<<i)) continue;
                
                int new_mask = (mask == 0 && i == 0) ? mask : (mask | 1<<i);
                
                ans += dfs(s, pos+1, 0, new_mask, dp);
                
                
            }
            
        }
        
        return dp[pos][tight][mask] = ans;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int mask_size = pow(2,n+3);
        vector<vector<vector<int>>> dp(n+3, vector<vector<int>>(2, vector<int>(1024, -1)));
        int num = pow(10, n)-1;
        string s = to_string(num);
        
        return dfs(s, 0, 1, 0, dp)+1;
    }
};