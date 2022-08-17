class Solution {
private:
    int dp[11][2][1024];
    
    int dfs(string& s, int pos, int tight, int mask){
        
        if(pos==s.length()){
            return mask!=0;
        }
        
        if(dp[pos][tight][mask]!=-1) {
            return dp[pos][tight][mask];
        }
        
        int ans=0;
        if(tight==1){
            
            // restriction case
            for(int i=0;i<=(s[pos]-'0');i++){
                
                if(mask & (1<<i)) continue;
                
                int new_mask = (mask == 0 && i==0 ? mask: (mask | 1<<i));
                
                if(i==(s[pos]-'0')){
                    
                    ans += dfs(s, pos+1, 1, new_mask);
                    
                } else {
                    
                    ans += dfs(s, pos+1, 0, new_mask);
                    
                }
                
            }
            
            
        } else {
            
            for(int i=0;i<=9;i++){
                
                if(mask & (1<<i)) continue;
                
                int new_mask = (mask == 0 && i==0 ? mask: (mask | 1<<i));
                
                ans += dfs(s, pos+1, 0, new_mask);
                
            }
            
            
        }
        
        return dp[pos][tight][mask] = ans;
        
    }
    
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 1, 0);
    }
};