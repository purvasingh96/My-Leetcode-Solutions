class Solution {
private:
    int res = 0;
    
    int dfs(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i >= nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        // dont make a connection
        int dontMake=0, make=0;
        dontMake = max(dfs(i+1, j, nums1, nums2, dp), dfs(i, j+1, nums1, nums2, dp));
        
        if(nums1[i] == nums2[j]){
            make += 1 + dfs(i+1, j+1, nums1, nums2, dp);
        }
        
        
        
        return dp[i][j] = max(dontMake, make);//max(res, ans);
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // for(auto x:dp){
        //     for(auto y:x) cout<<y<<" ";
        //     cout<<"\n";
        // }
        
        return dfs(0, 0, nums1, nums2, dp);
    }
};