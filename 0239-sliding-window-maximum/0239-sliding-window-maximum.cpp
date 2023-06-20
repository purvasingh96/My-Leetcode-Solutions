class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // TC: O(N), SC: O(K)
        
        deque<pair<int, int>> q;
        
        vector<int> res;
        int i=0;
        
       for(;i<k;i++){
           while(!q.empty() && q.back().second < nums[i]){
                   q.pop_back();
               }
               q.push_back({i, nums[i]});
       }
        
        res.push_back(q.front().second);
        
        for(;i<nums.size();i++){
            // pop_front: maintains current sliding window in deque
            while(!q.empty() && (i-q.front().first+1) >k){
                q.pop_front();
            }
            
            // pop_back: maintains decreasing monotonic queue
            while(!q.empty() && q.back().second < nums[i]){
                q.pop_back();
            }
            
            q.push_back({i, nums[i]});
            
            res.push_back(q.front().second);
        }
        
        return res;
        
        
    }
};