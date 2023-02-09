class Solution {
private:
    // dp[idx] -> min jumps to reach idx 
   long long dfs(int idx, vector<int>& nums, vector<long long>& dp){
        int n = nums.size();
       
        if(idx==n-1) {
            return 0;
        }
       
       if(dp[idx]!=INT_MAX) return dp[idx];
       
       long long minJumps=INT_MAX;
       for(int len=1;len<=nums[idx] && idx+len<n;len++){
           minJumps = min(minJumps, 1+ dfs(idx+len, nums, dp));
       }
       
       return dp[idx] = minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, INT_MAX);
        return dfs(0, nums, dp);
    }
};