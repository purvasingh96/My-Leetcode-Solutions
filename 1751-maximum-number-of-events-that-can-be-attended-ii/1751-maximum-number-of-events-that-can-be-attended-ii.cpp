class Solution {
private:
    int binary_search(int left, int right, vector<int> cur, vector<vector<int>>& e){
        int ans=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
        
            if(e[mid][0] > cur[1]){
                ans = mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        
        return ans;
    }
    
    int recur(int idx,vector<vector<int>>&events, int k, vector<vector<int>>& dp)
    {
        if(idx>=events.size() or k==0)
            return 0;
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int i = binary_search(idx+1, events.size()-1, events[idx], events);
        
        int op1=recur(idx+1,events,k, dp);
        int op2=events[idx][2]+recur(i,events,k-1, dp);
        
        return dp[idx][k] = max(op1,op2);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] !=b[0]){
                return a[0] < b[0];
            }
            return a[1]<b[1];
        });
        
        int n = events.size();
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return recur(0, events, k, dp);
        
    }
};