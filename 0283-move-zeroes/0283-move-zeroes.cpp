class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int lastNonZero=0, j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[lastNonZero++], nums[j]);
            }
        }
    }
};