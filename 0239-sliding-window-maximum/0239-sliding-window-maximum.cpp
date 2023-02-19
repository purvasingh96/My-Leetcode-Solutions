class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<vector<int>> pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i], i});
        }
        int right=k;
        vector<int> res;
        res.push_back(pq.top()[0]);
        
        while(right<nums.size()){
            while(!pq.empty() && right-pq.top()[1] >= k){
                pq.pop();
            }
            pq.push({nums[right], right});
            right+=1;
            res.push_back(pq.top()[0]);
        }
        
        return res;
    }
};