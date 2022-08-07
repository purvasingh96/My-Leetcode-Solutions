class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int prev=nums.back();
        long long ans=0;
        int n = nums.size();
        
        for(int i=n-2;i>=0;i--){
            
                int times =  nums[i]/prev;
                
               if(nums[i]%prev!=0) {
                   
                   times+=1;
                   prev = nums[i]/times;
                   
               }
                
                ans+= (times-1);
            }
        
        
        return ans;
    }
};