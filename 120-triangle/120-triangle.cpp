class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<vector<int>> dp(m);
        
        dp[0].resize(1);
        dp[0][0] = nums[0][0];
        
        for(int i=1;i<m;i++){
            int s = nums[i].size();
            dp[i].resize(s, INT_MAX);
            
            for(int j=0;j<s;j++){
                
               if(j==0){
                   
                   dp[i][j] = dp[i-1][j] + nums[i][j];
                   
               } else if(j == nums[i].size()-1){
                   
                   dp[i][j] = dp[i-1][j-1] + nums[i][j];
                   
               } else{
                   dp[i][j] = min(dp[i-1][j] + nums[i][j], dp[i-1][j-1]+nums[i][j]);
               }
                   
                
            }
            
        }
        
//         for(auto x:dp){
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<"\n";
//         }
        
        return *min_element(dp.back().begin(), dp.back().end());
        
    }
};