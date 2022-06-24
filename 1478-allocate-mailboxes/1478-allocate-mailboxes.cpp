class Solution {
private:
    int dp[101][101], costs[101][101];
    int n;
    
    int dfs(int housepos, int k){
        
        if(housepos >= n) return 0;
        if(k==1) return costs[housepos][n-1];
        if(dp[housepos][k]!=-1) return dp[housepos][k];
        
        int dist=INT_MAX;
        for(int i=housepos;i<n;i++){
            
            dist = min(dist, costs[housepos][i] + dfs(i+1, k-1));
            
        }
        
        return dp[housepos][k] = dist;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        n = houses.size();
        sort(houses.begin(), houses.end());
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                costs[i][j]=0;
                int median = houses[(i+j)/2];
                
                for(int k=i;k<=j;k++){
                    costs[i][j] += abs(median - houses[k]);
                }
                
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return dfs(0, k);
    }
};