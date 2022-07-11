class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = arr[i] == arr[i+1] ? 1:2;
        }
        
        for(int len=3;len<=n;len++){
            
            for(int left=0, right=left+len-1;right<n;left++, right++){
                
                if(arr[left] == arr[right]) {
                    dp[left][right] = dp[left+1][right-1];
                }
                
            
            
            for(int k=left;k<right;k++){
                
                dp[left][right] =   min(dp[left][right], 
                                    dp[left][k] + dp[k+1][right]);
                
                }
            }
            
        }
        
        return dp[0][n-1];
        
    }
};