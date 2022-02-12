class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> visited(nums.begin(), nums.end());
        
        return visited.size() < nums.size();
    }
};