class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(505);
        int res=INT_MAX;
        
        for(int i=0;i<=n;i++){
            for(int j=i;j>=0;j--){
                
                if(i==0 || j==0){
                    dp[j] = startFuel;
                } else if(dp[j-1] >= stations[i-1][0]){
                    dp[j] = max(dp[j], dp[j-1] + stations[i-1][1]);
                }
                
                if(dp[j] >= target) res = min(res, j);
            }
        }
        
        return res==INT_MAX?-1:res;
        
    }
    
};