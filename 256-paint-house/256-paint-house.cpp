class Solution {
public:
    int minCost(vector<vector<int>>& cost) {
        // recursion
        int n = cost.size();
        if(n==0) return 0;
        
        for(int i=n-2;i>=0;i--){
            cost[i][0] += min(cost[i+1][1], cost[i+1][2]);
            cost[i][1] += min(cost[i+1][0], cost[i+1][2]);
            cost[i][2] += min(cost[i+1][0], cost[i+1][1]);
        }
        
        return min(cost[0][0], min(cost[0][1], cost[0][2]));
    }
};