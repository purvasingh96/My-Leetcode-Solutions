class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];
        
        for(auto n:nums) {
            
            if(count==0) candidate = n;
            
            count += (n == candidate)?1:-1;
            
        }
        
        return candidate;
    }
};