typedef long long ll;
class Solution {
private:
    int search(int idx, vector<vector<int>>& rides){
        
        int target = rides[idx][1];
        
        int left=idx+1, right=rides.size()-1;
        int ans=-1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(rides[mid][0] >= target) {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        
        return ans;
    }
    
    
    ll dfs(int idx, vector<vector<int>>& rides, vector<ll>& dp) {
        
        if(idx>=rides.size() || idx<0){
            return 0;    
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        int i = search(idx, rides);
        ll dontpick = dfs(idx+1, rides, dp);
        
        ll pick = rides[idx][1]-rides[idx][0]+rides[idx][2] + dfs(i, rides, dp);    
        
        
        return dp[idx] = max(dontpick, pick);
        
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int x = rides.size();
        sort(rides.begin(), rides.end());
        vector<ll> dp(x+1, -1);
        return dfs(0, rides, dp);
    }
};