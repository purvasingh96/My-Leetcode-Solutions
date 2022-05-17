class Solution {

public:
    int dp[1001][1001];
    int helper(vector<int>& nums, vector<int>& muls, int start, int i){
        if(i==muls.size()) return 0;
        
        if(dp[i][start]!=-1) return dp[i][start];
        
        int end = nums.size() - (i-start) -1;
        
        int op1 = nums[start] * muls[i] + helper(nums, muls, start+1, i+1);
        int op2 = nums[end] * muls[i] + helper(nums, muls, start, i+1);
        
        return dp[i][start] = max(op1, op2);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
       
        memset(dp, -1, sizeof(dp));
        return helper(nums, multipliers, 0, 0);
        
    }
};