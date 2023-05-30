class Solution {
private:
    int get(int l, int r, vector<long long>& prefix){
        return prefix[r+1] - prefix[l];
    }
    int helper(int idx, int m, bool alice, vector<long long>& prefix, vector<int>& piles, vector<vector<vector<int>>>& dp){
        
        if(idx >= piles.size()) return 0;
        
        if(dp[idx][m][alice]!=-1) return dp[idx][m][alice];
        
        if(alice){
            int ans=0;
            for(int x=1;x<=2*m;x++){
                // including curr element
                if(idx+x-1<piles.size()) {
                    ans = max(ans, get(idx, idx+x-1, prefix) + helper(idx+x, max(m, x), false, prefix, piles, dp));
                }
            }
            
            return dp[idx][m][alice] = ans;
        } 
        
        int ans=INT_MAX;
        for(int x=1;x<=2*m;x++){
            if(idx+x-1 < piles.size()){
                ans = min(ans, helper(idx+x, max(m, x), true, prefix, piles, dp));
            }
        }
        
        return dp[idx][m][alice] = ans;
        
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + piles[i - 1];
        
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 2, vector<int>(2, -1)));
        return helper(0, 1, true, pref, piles, dp);
        
    }
};