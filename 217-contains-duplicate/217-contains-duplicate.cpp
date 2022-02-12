class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> visited;
        
        for(auto x:nums) {
            if(visited.find(x) != visited.end()) return true;
            visited.insert(x);
        }
        return false;
    }
};