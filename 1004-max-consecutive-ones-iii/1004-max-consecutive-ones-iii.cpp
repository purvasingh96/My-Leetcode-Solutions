class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int zeroes=0, ans=INT_MIN;
        
        for(int high=0;high<nums.size();high++){
            if(nums[high]==0){
                zeroes+=1;
            }
            if(zeroes>k){
                while(low<=high && zeroes>k){
                    if(nums[low] == 0){
                        zeroes-=1;
                    }
                    low+=1;
                }
            }
            ans = max(ans, high-low+1);
            
        } 
        
        return ans;
    }
};