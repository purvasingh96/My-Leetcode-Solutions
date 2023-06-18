class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum == target){
                return {l+1, r+1};
            } else if(sum > target){
                r-=1;
            } else {
                l+=1;
            }
        }
        
        return {l+1, r+1};
    }
};