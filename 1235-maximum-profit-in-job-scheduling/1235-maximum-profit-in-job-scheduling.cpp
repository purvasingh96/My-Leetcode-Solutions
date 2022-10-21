class Solution {
private:
    int binary_search(int start, vector<pair<pair<int, int>, int>>& nums, int target){
        int l=start, r=nums.size()-1;
        
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid].first.first >= target) r=mid;
            else l=mid+1;
        }
        //cout<<l<<"\n";
        //cout<<nums[l].first.first<<" "<<target<<"\n";
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
        
        // for(auto x:nums){
        //     cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
        // }
        
        
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1].second;
        
        for(int i=n-2;i>=0;i--){
            //cout<<"start: "<<nums[i].first.first<<" end: "<<nums[i].first.second<<"\n";
            int endTime = nums[i].first.second;
            int profit = nums[i].second;
                
            int idx = binary_search(i+1, nums, endTime);
           //cout<<"i: "<<i<<" idx: "<<idx<<"\n";
            
            if(idx!=-1){
                dp[i] = profit + dp[idx];
                dp[i] = max(dp[i], dp[i+1]);
            } else {
                dp[i] = max(profit, dp[i+1]);
            }
        }
        
        //for(auto x:dp) cout<<x<<" ";
        
        return dp[0];
        
    }
};