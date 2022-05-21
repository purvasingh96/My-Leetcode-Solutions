class Solution {
public:
    int dfs(vector<int>& coins, int remaining, vector<int>& count) {
        if(remaining <0) return -1;
        if(remaining == 0) return 0;
        
        if(count[remaining-1]!=0) return count[remaining-1];
        
        int minval=INT_MAX;
        
        for(auto coin:coins){
            int res  = dfs(coins, remaining-coin, count);
            if(res>=0 && res<minval) {
                minval = 1+res;
            }
        }
        
        count[remaining-1] = minval==INT_MAX?-1:minval;
        return count[remaining-1];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount, 0);
        return dfs(coins, amount, count);
    }
};