class Solution {
private:
    
    int dfs(vector<int>& nums, vector<int>& muls, int i, int start,vector<vector<int>>& dp){
        
        if(i>=muls.size()) {
            return 0;
        }
        
        int end = (nums.size()-1) - (i-start);
        
        if(dp[i][start]!=INT_MIN) return dp[i][start];
        
        int choose_front = muls[i]*nums[start] + dfs(nums, muls, i+1, start+1, dp);
        int choose_back = muls[i]*nums[end] + dfs(nums, muls, i+1, start, dp);
        
        return dp[i][start] = max(choose_front, choose_back);
        
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size(), m=multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m, INT_MIN));
        return dfs(nums, multipliers, 0, 0, dp);
        
    }
};