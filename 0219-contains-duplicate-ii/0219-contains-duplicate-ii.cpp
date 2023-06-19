class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int l=0, r=0;
        for(;r<=k && r<nums.size();r++) {
            m[nums[r]]+=1;
            if(m[nums[r]] > 1) return true;
        }
        
        for(;r<nums.size();r++){
            m[nums[r]]+=1;
            m[nums[l]]-=1;
            l+=1;
            if(m[nums[r]] > 1) return true;
            
        }
        
        return false;
        
    }
};