class Solution {
private:
    long long dfs(int pos, int fuel, int finish, vector<int>& locations, vector<vector<long long>>& dp){
        int mod = 1e9+7;
        
        
        if(dp[pos][fuel]!=-1) return dp[pos][fuel];
        
        long long c=0;
        if(fuel>=0 && pos == finish) c+=1;
        for(int j=0;j<locations.size();j++){
            int dist = abs(locations[j] - locations[pos]);
            if(j!=pos && dist <=fuel){
                c += dfs(j, fuel - abs(locations[j] - locations[pos]), finish, locations, dp);
            c=c%mod;
            }
            
        }
        
        return dp[pos][fuel] = c;
        
        
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<long long>> dp(n, vector<long long>(fuel+1, -1));
        return dfs(start, fuel, finish, locations, dp);
    }
};