class Solution {
private:
    int mod = 1e9;
    int dfs(int hatVal, int mask, int ending_mask, vector<vector<int>>& hatsToPeople, vector<vector<long>>& dp){
        
        if(mask == ending_mask) return 1;
        if(hatVal>40) return 0;
        if(dp[hatVal][mask]!=-1) return dp[hatVal][mask];
        
        long pick=0;
        
        long dontpick = dfs(hatVal+1, mask, ending_mask, hatsToPeople, dp);
        
        dontpick = dontpick%(int)(1e9 + 7);;
        
        for(auto people:hatsToPeople[hatVal]){
            
            if((mask & (1<<people)) == 0){
                pick += dfs(hatVal+1, (mask | 1<<people), ending_mask, hatsToPeople, dp);
                pick = pick%(int)(1e9 + 7);;
            }
        }
        
        
        return dp[hatVal][mask] = (pick + dontpick)%(int)(1e9 + 7);;
        
    }
    
public:
    int numberWays(vector<vector<int>>& hats) {
        long n = hats.size();
        long mask_size = pow(2, n);
        int mask=0, res=0;
        
        vector<vector<long>> dp(41, vector<long>(mask_size, -1));
        
        vector<vector<int>> hatsToPeople(41);
        
        
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                hatsToPeople[hats[i][j]].push_back(i);
            }
        }
        
        int ending_mask = (1<<n)-1;
        
        return dfs(1, mask, ending_mask, hatsToPeople, dp);
    }
};