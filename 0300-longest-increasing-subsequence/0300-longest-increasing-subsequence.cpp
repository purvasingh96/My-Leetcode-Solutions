class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
            } else{
                int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[idx]=nums[i];
            }
        }
        return res.size();
    }
};