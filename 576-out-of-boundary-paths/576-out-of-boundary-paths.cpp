class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int mod = 1e9+7;
    
    bool withinBounds(int r, int c, int m, int n){
        return (r>=0 && c>=0 && r<m && c<n);
    }
    
    bool outOfBounds(int r, int c, int m, int n){
        return (r<0 || c<0 || r>=m || c>=n);
    }
    
    long dfs(int r, int c, int movesLeft, int m, int n, vector<vector<vector<long>>>& dp){
        
        //if(withinBounds(r, c, m, n) && movesLeft==0) return 0;
        
        if(outOfBounds(r, c, m, n) && movesLeft>=0) return 1;
        
        if(movesLeft<0) return 0;
        
        if(withinBounds(r, c, m, n) && dp[r][c][movesLeft]!=-1){
            
            return dp[r][c][movesLeft];            
        }
        
        long ans=0;
        
        for(int i=0;i<4;i++){
            int new_r = r + dx[i];
            int new_c = c + dy[i];
            
            ans += dfs(new_r, new_c, movesLeft-1, m, n, dp);
            ans = ans%mod;  
        }
        
        return dp[r][c][movesLeft] = ans;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long ans=0;
        vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(maxMove+1, -1)));
        
        return (int)dfs(startRow, startColumn, maxMove, m, n, dp);
        
    }
};