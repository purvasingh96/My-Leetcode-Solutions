class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        
        
        int l = 0, r = nums.size()-1;
        int ops=0;
        
        while(l<r) {
            
            int sum = nums[l]+nums[r];
            
            if(sum == k) {
                ops += 1;
                l+=1;
                r-=1;
            } else if(sum < k) {
                l+=1;
            } else{
                r-=1;
            }
        }
        
        return ops;
        
    }
};