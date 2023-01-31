class Solution {
private:
    int binary_search(int idx, vector<vector<int>>& events){
        int res = events[idx][1], n = events.size();
        int s = idx+1, e=n-1;
        int ans=n;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(events[mid][0] > res){
                ans=mid;
                e=mid-1;
            } else{
                s=mid+1;
            }
        }
        
        return ans;
        
    }
    
    
    int dfs(int idx, int k, vector<vector<int>>& dp, vector<vector<int>>& events){
        
        if(idx >= events.size() || k<=0) return 0;
        
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int skip=-1, dontSkip=-1;
        int next = binary_search(idx, events);
        //cout<<"idx: "<<idx<<" next: "<<next<<"\n";
        
        skip = dfs(idx+1, k, dp, events);
        
        dontSkip = events[idx][2] + dfs(next, k-1, dp, events);
        
        return dp[idx][k] = max(skip, dontSkip);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[2] > b[2];
            return a[0] < b[0];
        });
        
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        return dfs(0, k, dp, events);
        
        
    }
};