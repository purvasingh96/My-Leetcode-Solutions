class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        deque<int> q;
        
        for(int i=0;i<nums.size();i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                res[q.back()] = (i-q.back());
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return res;
    }
};