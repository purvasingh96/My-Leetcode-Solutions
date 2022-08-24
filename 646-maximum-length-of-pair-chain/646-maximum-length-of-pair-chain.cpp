class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // knapsack types
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(pairs[j][1] < pairs[i][0]){
                    
                    dp[i] = max(dp[i], dp[j]+1);
                    
                }
                
                
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};