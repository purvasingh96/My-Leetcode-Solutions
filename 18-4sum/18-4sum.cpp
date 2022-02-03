class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, target, 0, 4);
    }
    
    vector<vector<int>> ksum(vector<int>& nums, int target, int start, int k) {
        
        vector<vector<int>> res;
        
        if(start == nums.size()) {
            
            return res;
            
        }
        
        int avg = target/k;
        
        if(nums[start] > avg || nums.back()<avg) {
            return res;
        }
        
        if(k==2) return twoSum(nums, target, start);
        
        for(int i=start;i<nums.size();i++) {
            
            if(i==start || nums[i-1]!=nums[i]) {
                for(auto& v:ksum(nums, target-nums[i], i+1, k-1)) {
                
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(v), end(v));
                
            }
            }
            
        }
        
        return res;
        
    }
    
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        int left=start, right=nums.size()-1;
        
        while(left < right) {
            
            int cur_sum = nums[left] + nums[right];
            
            if(cur_sum < target || (left>start && nums[left] == nums[left-1])) {
                
                left += 1;
                
            } else if(cur_sum > target || (right < nums.size()-1 && nums[right] == nums[right+1])) {
                
                right-=1;
                
            } else {
                
                res.push_back({nums[left++], nums[right--]});
                
            }
            
        }
        
        return res;
    }
    
};