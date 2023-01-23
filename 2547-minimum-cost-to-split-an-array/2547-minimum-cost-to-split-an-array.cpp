class Solution {
private:
    int dfs(int idx, int k, vector<int>& dp, vector<int>& nums, vector<vector<int>>& split){
        
        if(idx >= nums.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
            
        int ans=INT_MAX;
        for(int i=idx;i<nums.size();i++){
            int val = split[idx][i] + k + dfs(i+1, k, dp, nums, split);
            ans= min(ans, val);
        }
        
        return dp[idx] = ans;
    }
    
    
public:
    int minCost(vector<int>& nums, int k) {
        vector<vector<int>> split(1001, vector<int>(1001, 0));
        vector<int> dp(1001, -1);
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            unordered_map<int, int> m;
            int trim=0;
            
            for(int j=i;j<n;j++){
                m[nums[j]]+=1;
                if(m[nums[j]] == 2) trim+=2;
                else if(m[nums[j]] > 2) trim +=1;
                
                split[i][j] = trim;
            }
        }
        
        return dfs(0, k, dp, nums, split);
        
    }
};