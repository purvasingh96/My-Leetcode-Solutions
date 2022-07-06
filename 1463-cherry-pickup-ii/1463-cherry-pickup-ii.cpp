class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& memo,
        int r1, int c1, int r2, int c2, int m, int n){
        
        if(r1<0 || r2<0 || c1<0 || c2<0 || 
          r1>=m || r2>=m || c1>=n || c2>=n){
            return INT_MIN;
        }
        
        if(r1==m-1 && r2==m-1){
            if(c1==c2) return grid[r1][c1];
            return grid[r1][c1]+grid[r2][c2];
        }
       
        if(memo[r1][c1][r2][c2]!=-1){
            return memo[r1][c1][r2][c2];
        }
        
        int ans = grid[r1][c1];
        
        if(r1!=r2 || c1!=c2){
            ans += grid[r2][c2];
        }
        
        int a = max(dfs(grid, memo, r1+1, c1, r2+1, c2, m, n), dfs(grid, memo, r1+1, c1, r2+1, c2+1, m, n));
        int b = max(dfs(grid, memo, r1+1, c1, r2+1, c2-1, m, n), dfs(grid, memo, r1+1, c1+1, r2+1, c2, m, n));
        int c = max(dfs(grid, memo, r1+1, c1+1, r2+1, c2-1, m, n), dfs(grid, memo, r1+1, c1+1, r2+1, c2+1, m, n));
        int d = max(dfs(grid, memo, r1+1, c1-1, r2+1, c2, m, n), max(dfs(grid, memo, r1+1, c1-1, r2+1, c2-1, m, n), 
                                                                dfs(grid, memo, r1+1, c1-1, r2+1, c2+1, m, n)));
            
        int res = max(a, max(b, max(c, d)));
        ans+=res;
        
        
        return memo[r1][c1][r2][c2] = ans;
        
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<int>>>> memo(m, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, -1))));
        
        return dfs(grid, memo, 0, 0, 0, n-1, m, n);
        
    }
};