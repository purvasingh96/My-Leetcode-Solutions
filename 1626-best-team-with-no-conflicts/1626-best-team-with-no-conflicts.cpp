class Solution {
private:
    int dfs(int idx, int lastIdx, vector<vector<int>>& dp, vector<pair<int, int>>& nums){
        if(idx >= nums.size()) return 0;
        if(dp[lastIdx+1][idx]!=-1) return dp[lastIdx+1][idx];
        
        int skip=-1, dontSkip=-1;
        skip = dfs(idx+1, lastIdx, dp, nums);
        
        
        if(lastIdx==-1 || nums[idx].first == nums[lastIdx].first || nums[lastIdx].second <= nums[idx].second) {
            dontSkip = nums[idx].second + dfs(idx+1, idx, dp, nums);
        }
        
        return dp[lastIdx+1][idx] = max(skip, dontSkip);
        
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<pair<int, int>> nums;
        
        for(int i=0;i<n;i++){
            nums.push_back({ages[i], scores[i]});
        }
        
        
        sort(nums.begin(), nums.end());
        //for(auto x:nums) cout<<x.first<<" "<<x.second<<"\n";
        return dfs(0, -1, dp, nums);
        
    }
};