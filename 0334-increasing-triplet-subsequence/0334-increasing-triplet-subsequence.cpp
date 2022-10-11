class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            if(res.empty() || (nums[i] > res.back() && res.size() < 3)) {
                res.push_back(nums[i]);
                if(res.size()==3) return true;
            }
            else{
                auto it = lower_bound(res.begin(), res.end(), nums[i]);
                
                int pos = it-res.begin();
                res[pos] = nums[i];
            }
        }
        
        return res.size()==3;
        
    }
};