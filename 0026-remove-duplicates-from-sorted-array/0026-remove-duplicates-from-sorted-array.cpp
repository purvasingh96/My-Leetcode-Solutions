class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int prev=0;
        int pos=0;
        while(i+1<nums.size()){
            int idx = upper_bound(nums.begin()+i, nums.end(), nums[i]) - nums.begin();
            if(idx!=nums.size()){
                nums[++pos] = nums[idx];
            }
            i=idx;
        }
        
        return pos+1;
    }
};