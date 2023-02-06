class Solution {
private:
    long long dfs(int i, int k, vector<vector<int>>& cost, vector<vector<long long>>& dp, vector<int>& houses){
        int n = houses.size();
        if (i == houses.size() && k == 0) return 0;
        if (i == houses.size() || k == 0) return INT_MAX;
        
        
        if(dp[i][k]!=-1) return dp[i][k];
        
        long long ans=INT_MAX;
        for(int j=i;j<n;j++){
            long long temp = cost[i][j] + dfs(j+1, k-1, cost, dp, houses);
            ans = min(ans, temp);
        }
        
        return dp[i][k] = ans;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<int>> cost(n, vector<int>(n, 0));
        vector<vector<long long>> dp(n, vector<long long>(k+1, -1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mid = houses[(i+j)/2];
                for(int k=i;k<=j;k++){
                    cost[i][j] += abs(houses[k] - mid);
                }
            }
        }
        
        return (int)dfs(0, k, cost, dp, houses);
    }
};