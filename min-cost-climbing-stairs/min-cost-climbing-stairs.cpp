class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = INT_MAX;
        
        int p0=0;
        int p1=0;
        
        for(int i=2;i<=n;i++) {
            ans = min((cost[i-2]+p0), (cost[i-1]+p1));
            p0=p1;
            p1=ans;
            
        }
        
        return ans;
        
    }
};