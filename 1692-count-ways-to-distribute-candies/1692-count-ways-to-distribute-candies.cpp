class Solution {
private:
    int mod = 1e9+7;
    int dfs(int candies, int bags, vector<vector<int>>& memo){
        
        if(bags==1 || candies == bags) return 1;
        if(candies==0 || bags==0 || candies<bags) return 0;
        
        
        if(memo[candies][bags]!=-1) return memo[candies][bags];
        
        long temp = 1L*bags*dfs(candies-1, bags, memo)%mod + dfs(candies-1, bags-1, memo);
        
        return memo[candies][bags] = (int)temp%mod;
        
    }
public:
    int waysToDistribute(int n, int k) {
        vector<vector<int>> memo(n+1, vector<int>(k+1, -1));
       return dfs(n, k, memo);
    }
};