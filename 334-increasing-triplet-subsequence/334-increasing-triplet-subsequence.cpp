class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] > res.back()){
                res.push_back(nums[i]);
                if(res.size()>=3) return true;
            } else {
                auto it = lower_bound(res.begin(), res.end(), nums[i]);
                res[it-res.begin()] = nums[i];
            }
        }
        
        return false;
    }
};