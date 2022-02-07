class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int seenOnce = 0, seenTwice = 0;
        
        for(auto n:nums) {
            
            seenOnce = ~seenTwice & (seenOnce ^ n);
            seenTwice = ~seenOnce & (seenTwice ^ n);
            
        }
        
        return seenOnce;
        
    }
};