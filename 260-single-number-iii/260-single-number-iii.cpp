class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int bitmask = 0;
        for(auto n:nums) bitmask ^= n;
        
        // get the rightmost 1-bit diff between x & y
        int diff=1;
        
        while(1) {
            
            if((bitmask & diff) == 0) {
                diff = diff << 1;
            } else break;
            
        }
        
        int x=0, y=0;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++) {
           if((nums[i] & diff) !=0) {
               x ^= nums[i];
           } else{
               y ^= nums[i];
           }
        }
        
        res.push_back(x);
        res.push_back(y);
        
        return res;
        
    }
};