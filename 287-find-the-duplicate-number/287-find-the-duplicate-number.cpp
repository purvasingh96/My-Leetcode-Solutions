class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];
        
        // do we have a cycle?
        
        do {
            
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            
        } while(hare!=tortoise);
        
        tortoise = nums[0];
        
        while(tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
            
        
    }
};