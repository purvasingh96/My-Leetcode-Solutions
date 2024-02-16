class Solution {
public:
    unordered_map<int, vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = m[target].size();
        return m[target][rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */