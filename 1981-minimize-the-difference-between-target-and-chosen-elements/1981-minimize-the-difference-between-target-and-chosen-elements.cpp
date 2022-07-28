class Solution {
private:
    //int res=INT_MAX;
    int dp[72][5000];
    int dfs(int i, int sum, int target, vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        
        if(i==m) return abs(target-sum);
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans, dfs(i+1, sum+mat[i][j], target, mat));
            if(ans==0) break;
        }
        
        return dp[i][sum] = ans;
    }
    
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, target, mat);
    }
};