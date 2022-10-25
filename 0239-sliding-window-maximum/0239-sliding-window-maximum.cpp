class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int start=0;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            
            if(q.empty() || nums[q.back()] >= nums[i]){
                q.push_back(i);
            } else{
                
                while(!q.empty() && nums[q.back()] < nums[i]){
                    q.pop_back();
                }
                q.push_back(i);
                
            }
            
            if(i-start+1 == k){
                res.push_back(nums[q.front()]);
                start+=1;
                while(!q.empty() && start > q.front()) q.pop_front();
            }
        }
        
        return res;
        
    }
};