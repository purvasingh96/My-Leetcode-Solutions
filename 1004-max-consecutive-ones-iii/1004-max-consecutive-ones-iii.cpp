class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int c=0;
        int ans=0;
        
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                c+=1;
            }
            
            if(c <= k){
                ans = max(ans, right-left+1);
            }
            
            
            
            if(c>k){
               while(left<right && c > k){
                    if(nums[left]==0){
                        c-=1;
                    }
                    left+=1;
                }
            }
            
        }
        
        return ans;
    }
};