class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // decreasing monotonic queue
        deque<pair<int, int>> q;
        vector<int> ans;
        int i=0;
        
        for(;i<k;i++){
            while(!q.empty() && q.back().first < nums[i]){
                q.pop_back();
            }
            q.push_back({nums[i], i});
        }
        
        ans.push_back(q.front().first);
        
        for(;i<nums.size();i++){
            
            // decreasing mono queue
            while(!q.empty() && q.back().first <nums[i]){
                q.pop_back();
            }
            
            // out of bounds
            while(!q.empty() && i-q.front().second+1 > k){
                q.pop_front();
            }
            
            q.push_back({nums[i], i});
            ans.push_back(q.front().first);
        }
        
        return ans;
    }
};