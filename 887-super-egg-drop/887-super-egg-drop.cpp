class Solution {
private:
    int dfs(int e, int f, vector<vector<int>>& dp){
        
        if(f==0 || f==1){
            return f;
        }
        
        if(e==1){
            return f;
        }
        
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        
        int mn=f;
        
        int low =1, high=f;
        
        while(low<high){
            
            int mid = low + (high-low)/2;
            
            int left = dfs(e-1, mid-1, dp);
            int right = dfs(e, f-mid, dp);
            
            mn = min(mn, 1+max(left, right));
            
            
            if(left<right){
                low=mid+1;
            } else {
                high=mid;
            }
            
        }
        
        return dp[e][f]=mn;
        
    }
public:
    int superEggDrop(int k, int n) {
        if(k==1 || n==1) return n;
        
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        dfs(k, n, dp);
        return dp[k][n];
    }
};