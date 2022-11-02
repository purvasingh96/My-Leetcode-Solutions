class Solution {
    
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=0, i=0;
        
        while(i<nums.size()){
            if(i!=0 && nums[i] == nums[i-1]) {
                while(i<nums.size() && nums[i] == nums[i-1]){
                    i+=1;
                }
            } else{
              int target = nums[i] + k;
                auto it = lower_bound(nums.begin()+i+1, nums.end(), target);
                if(it!=nums.end() && nums[it - nums.begin()]==target){
                    ans+=1;
                }  
                i+=1;
            }
            
        }
        
        return ans;
    }
};