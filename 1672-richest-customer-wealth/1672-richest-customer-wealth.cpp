class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int max_wealth = INT_MIN;
        
        for(auto x:accounts) {
            
            int sum = accumulate(x.begin(), x.end(), 0);
            
            max_wealth = max(max_wealth, sum);
            
        }
        
        return max_wealth;
        
    }
};