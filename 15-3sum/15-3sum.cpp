class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        return threeSum(nums, 0, 0, 3);
        
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target, int k) {
        
        vector<vector<int>> res;
        
        if(start == nums.size()) return res;
        
        int avg = target/k;
        
        if(nums[start] > avg || avg > nums.back()) {
            return res;
        }
        
        if(k==2) return twoSum(nums, start, target);
        
        for(int i=start;i<nums.size();i++) {
            
            if(i==start || nums[i]!=nums[i-1]) {
                
                for(auto v:threeSum(nums, i+1, target-nums[i], k-1)) {
                    
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(v), end(v));
                    
                }
                
            }
            
        }
        
        return res;
        
    }
    
    
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        
        int left=start, right=nums.size()-1;
        vector<vector<int>> res;
        
        while(left < right) {
            
            int sum = nums[left] + nums[right];
            
            if(sum < target || (left > start && nums[left]==nums[left-1])) {
                
                left+=1;
                
            } else if(sum > target || (right < nums.size()-1 && nums[right] == nums[right+1])) {
                
                right -= 1;
                
            } else {
                
                res.push_back({nums[left++], nums[right--]});
                
            }
            
            
        }
        
        return res;
        
    }
    
};