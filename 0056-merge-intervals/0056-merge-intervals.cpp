class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
     // sort by start
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++){
            if(res.size() ==0 || res.back()[1] < nums[i][0]){
                res.push_back(nums[i]);
            } else {
                auto f = res.back();
                res.pop_back();
                res.push_back({f[0], max(f[1], nums[i][1])});
            }
        }
        
        return res;
    }
};