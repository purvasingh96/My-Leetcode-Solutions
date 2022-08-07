class Solution {
private:
    bool dfs(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i==n) return true;
        
        if(dp[i]!=-1) return dp[i]==1;
        
        bool x=false, y=false, z=false;
        
        if(i+1<n) {
            if(nums[i] == nums[i+1]) {
                x = dfs(i+2, nums, dp);
            }
        } 
        
        if(i+2<n){
            
            if((nums[i] == nums[i+1]) && (nums[i+1] == nums[i+2])){
                y = dfs(i+3, nums, dp);
            } 
            
            else if((nums[i+2] == nums[i+1]+1) && (nums[i+1] == nums[i]+1)){
                z = dfs(i+3, nums, dp);
            }
            
        }
        
        return dp[i] = (x||y||z);
        
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(0, nums, dp);
    }
};