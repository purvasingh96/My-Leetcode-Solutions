class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_nonzero_pos=0;
        
        // lnp: tracks nonzero elems, 
        // i: general iter
        
        // if(n(i)!=0) np[lnp++]  = n[i];
        // convert all elements after lnp till end to 0
        // TC: O(N), SC: O(1)
        
        for(int i=0;i<nums.size();i++) {
            
            if(nums[i]!=0) {
                nums[last_nonzero_pos++] = nums[i];
            }
            
        }
        
        for(int i=last_nonzero_pos;i<nums.size();i++) {
            nums[i] = 0;
        }
        
    }
};