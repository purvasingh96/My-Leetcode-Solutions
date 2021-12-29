class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        Pseudo code:
        - map m,
        - for i: 0 to nums.size()-1
            - if (target - nums[i]) present in m:
                - return {m[target - nums[i]], i}
            - m[nums[i]] = i
        - endfor
        
        TC: O(N)
        
        */
        map<int, int> idx;
        
        for(int i=0;i<nums.size();i++) {
            
            if(idx.find(target - nums[i]) != idx.end()) {
                
                return {idx[target - nums[i]], i};
                
            }
            
            idx[nums[i]] = i;
            
        }
        
        return {};
    }
};