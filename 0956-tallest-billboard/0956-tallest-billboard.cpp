class Solution {
private:
    int dfs(int idx, int first, int second, vector<int>& rods, vector<vector<int>>& dp){
        if(idx>=rods.size()){
            if(first == second) return 0;
            else return INT_MIN;
        }
        
        if(dp[idx][abs(first - second)]!=-1) return dp[idx][abs(first - second)];
        
        return dp[idx][abs(first - second)] = max({dfs(idx+1, first, second, rods, dp), 
                                                rods[idx]+dfs(idx+1, first+rods[idx], second, rods, dp),
                                               rods[idx]+dfs(idx+1, first, second+rods[idx], rods, dp)});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return dfs(0, 0, 0, rods, dp)/2;
    }
};