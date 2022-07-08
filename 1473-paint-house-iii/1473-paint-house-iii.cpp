class Solution {
private:
    int dfs(int i, int prev, int curN, int target, vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>>& memo, int m, int n){
        
        if(i == m){
            if(curN!=target) return 1000001;
            else return 0;
        } 
        
        if(curN > target){
            return 1000001;
        }
        
        if(memo[i][curN][prev]!=-1){
            return memo[i][curN][prev];
        }
        
        int mincost=1000001;
        
        if(houses[i]){
            
            int newN = curN + (houses[i]==prev?0:1);
            mincost = min(mincost, dfs(i+1, houses[i], newN, target, houses, cost, memo, m, n));
            
        } else{
            
            for(int j=1;j<=n;j++){
                
                int newN = curN + (j==prev?0:1);
                int curCost = cost[i][j-1] + dfs(i+1, j, newN, target, houses, cost, memo, m, n);
                mincost = min(mincost, curCost);
                
            }
            
            
        }
        
        return memo[i][curN][prev] = mincost;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(100, vector<vector<int>>(100, vector<int>(21, -1)));
        int ans = dfs(0, 0, 0, target, houses, cost, memo, m, n);
        return ans==1000001?-1:ans;
    }
};