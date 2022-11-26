class Solution {
private:
    int binary_search(int start, vector<pair<pair<int, int>, int>>& nums, int target){
        int l=start, r=nums.size()-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid].first.first >= target) r=mid;
            else l=mid+1;
        }
        
        if(nums[l].first.first < target) return -1;
        return l;
    }
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pair<pair<int, int>, int>> nums;
        int n = p.size();
        
        for(int i=0;i<n;i++){
            nums.push_back({{s[i], e[i]}, p[i]});
        }
        
        
        sort(nums.begin(), nums.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>&b ){
            pair<int,int> ka = a.first;
            pair<int,int> kb = b.first;
            
            if(ka.first == kb.first) return ka.second < kb.second;
            return ka.first < kb.first;
        });
        
        
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1].second;
        
        for(int i=n-2;i>=0;i--){
            
            int endTime = nums[i].first.second;
            int profit = nums[i].second;
                
            int idx = binary_search(i+1, nums, endTime);
            
            if(idx!=-1){
                dp[i] = profit + dp[idx];
                dp[i] = max(dp[i], dp[i+1]);
            } else {
                dp[i] = max(profit, dp[i+1]);
            }
        }
        
        
        return dp[0];
        
    }
};