class Solution {
public:
    string minWindow(string s1, string s2) {
        int m =s1.length(), n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int i=0;i<m;i++){
            if(s1[i] == s2[0]){
                
                dp[i][0] = i;
                
            }
        }
        
        for(int j=1;j<n;j++){
            
            int k=-1;
            
            for(int i=0;i<m;i++){
                
                if(k!=-1 && s1[i] == s2[j]){
                    dp[i][j]=k;
                }
                
                k=max(k, dp[i][j-1]);
                
            }
            
        }
        
        int minlen=INT_MAX, start=-1, end=-1;
        for(int i=0;i<m;i++){
            if(dp[i][n-1]==-1) continue;
            
            int curr_len = i-dp[i][n-1]+1;
            if(curr_len < minlen){
                minlen=curr_len;
                start=dp[i][n-1];
                end=i;
            }
            
        }
        if(start==-1) return "";
        return s1.substr(start, end-start+1);
    }
};