class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int minsofar=nums[0], maxsofar=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int tempminsofar = minsofar;
            int tempmaxsofar = maxsofar;
            minsofar = min(nums[i], min(minsofar*nums[i], maxsofar*nums[i]));
            maxsofar = max(nums[i], max(tempminsofar*nums[i], tempmaxsofar*nums[i]));
            res = max(res, max(minsofar, maxsofar));
        }
        
        return res;
    }
};