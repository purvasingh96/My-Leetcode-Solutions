class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        int i=0;
        vector<int> res;
        
        for(;i<k;i++){
            while(!q.empty() && q.back().first < nums[i]){
                    q.pop_back();
                }
            q.push_back({nums[i], i});
        }
        
        res.push_back(q.front().first);
        
        for(;i<nums.size();i++){
            // pop back to maintain decreasing monotonic queue
            while(!q.empty() && q.back().first < nums[i]){
                q.pop_back();
            }
            
            q.push_back({nums[i], i});
            
            while(!q.empty() && (i - q.front().second) >= k){
                q.pop_front();
            }
            
            res.push_back(q.front().first);
            
        }
        
        return res;
        
    }
};