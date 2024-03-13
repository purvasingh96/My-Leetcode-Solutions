class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int l=0, r=0;
        int len=-1;
        for(;r<nums.size();r++){
            if(r>0 && nums[r]<=nums[r-1]){
                len = max(len, r-l);
                l=r;
            }
        }
        
        return len==-1 ? nums.size() : max(len, r-l);
    }
};