class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0]==k;
        
        int n = nums.size();
        int left=0, right=0;
        int gcdSoFar=-1;
        int c=0;
        
       for(int i=0;i<nums.size();i++){
           int gcdx=nums[i];
           if(gcdx==k) c+=1;
           
           for(int j=i+1;j<n;j++){
               int new_gcdx = gcd(gcdx, nums[j]);
               if(new_gcdx==k){
                   c+=1;
               }
               gcdx = new_gcdx;
           }
       }
                                
        return c;                        
        
    }
};