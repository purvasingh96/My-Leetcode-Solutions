class Solution {
private:
    int dfs(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i>word1.length() || j>word2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(word1[i] == word2[j]){
            ans = dfs(i+1, j+1, word1, word2, dp);
        } else{
            // insert
            int insert = dfs(i, j+1, word1, word2, dp);
            int _delete = dfs(i+1, j, word1, word2, dp);
            int replace = dfs(i+1, j+1, word1, word2, dp);
            ans = 1+ min({insert,_delete, replace});
        }
        cout<<"i: "<<i<<"j: "<<j<<"ans: "<<ans<<"\n";
        return dp[i][j] = ans;
    }
    
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int val=0;
        for(int i=m;i>=0;i--){
            dp[i][n] = (val);
            val+=1;
        }
        val = 0;
        for(int j=n;j>=0;j--){
            dp[m][j] = (val);
            val+=1;
        }
       
        dfs(0,0, word1, word2, dp);
        
        return dp[0][0];
    }
};