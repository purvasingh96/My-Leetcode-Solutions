class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int left=0, right=1, res=0;
        
        while(left < nums.size() && right < nums.size()) {
            
            if(left == right || nums[right] - nums[left] < k) {
                
                right+=1;
                
            } else if(nums[right] - nums[left] > k) {
                
                left += 1;
                
            } else {
                
                left += 1;
                res += 1;
                
                while(left < nums.size() && nums[left] == nums[left-1]) {
                    
                    left+=1;
                    
                }
                
            }
            
        }
        
        return res;
        
        
    }
};