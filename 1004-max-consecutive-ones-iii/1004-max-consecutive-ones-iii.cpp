class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0;
        int ans=0;
        int l=0, r=0;
        
        
        while(r<nums.size()){
            if(nums[r] ==0){
                c+=1;
            }
            
            while(l<=r && c>k){
                if(nums[l] == 0){
                    c-=1;
                }
                l+=1;
            }
            
            ans = max(ans, r-l+1);
            r+=1;
                
        }
        
        return ans;
        
    }
};