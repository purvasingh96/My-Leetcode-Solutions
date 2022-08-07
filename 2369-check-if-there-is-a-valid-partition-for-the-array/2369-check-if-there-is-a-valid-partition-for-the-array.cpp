class Solution {
private:
    bool helper(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i==n) return true;
        
        if(dp[i]!=-1) return dp[i]==1;
        
        bool x=false, y=false;
        
        if(i+1<n) {
            if(nums[i] == nums[i+1]) {
                x = helper(i+2, nums, dp);
            }
        } 
        
        if(i+2<n){
            
            bool cond_1 = ((nums[i] == nums[i+1]) && (nums[i+1] == nums[i+2]));
            bool cond_2 = ((nums[i+2] == nums[i+1]+1) && (nums[i+1] == nums[i]+1));
            
            if(cond_1 || cond_2){
                y = helper(i+3, nums, dp);
            }
            
        }
        
        return dp[i] = (x||y);
        
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }
};