class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
            1. sliding window 
            2. n = (R-L) ans += n(n-1)/2;
            3. ans += 1 if(nums[i]<k)
            4. return ans;
            
            TC: O(N) SC:O(1)
        */
        if(k==0) return 0;
        int left=0, right=0;
        int n = nums.size();
        int prod=1, ans=0;
        
       for(int right=0;right<n;right++){
           prod *= nums[right];
           
           while(left<=right && prod>=k){
               prod = prod/nums[left++];
           }
           ans+=(right-left+1);
       }
        
        return ans;
        
    }
};