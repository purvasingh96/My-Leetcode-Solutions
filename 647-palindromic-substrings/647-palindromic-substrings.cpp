class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        
        // base case
        for(int j=0;j<n;j++){
            dp[0][j]=1;
            dp[1][j]=1;
        }
        
        int res = s.length();
        
        for(int i=2;i<n+1;i++){
            
            for(int j=0;j<n;j++){
                
                if(j+i-1<n && s[j] == s[j+i-1]){
                    
                    if(dp[i-2][j+1]) {
                        
                        dp[i][j]+=1;
                        res+=1;
                        
                    }
                    
                }
                
            }
            
        }

        
        return res;
            
    }
};