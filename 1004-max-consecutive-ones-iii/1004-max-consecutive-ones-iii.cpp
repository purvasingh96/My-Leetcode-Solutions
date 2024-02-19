class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0, high=0;
        int c=0;
        int res=INT_MIN;
        
        while(high<nums.size()){
            if(nums[high]==0){
                c+=1;
            }
            
            if(c>k){
                while(low<=high && c>k){
                    if(nums[low] == 0){
                        c-=1;
                    }
                    low+=1;
                }
            }
            res = max(res, high-low+1);
            high+=1;
        }
        
        return res;
    }
};