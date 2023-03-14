class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        kSum(nums, 0, 3);
        return ans;
    }
    void kSum(vector<int>& nums, int target, int k) {
        vector<int> tmp;
        dfs(nums, 0, (int)nums.size() - 1, k, target, tmp);
    }
    void dfs(vector<int>& nums, int l, int r, int k, int target, vector<int>& path) {
        if (k == 2) {
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    while (l+1 < r && nums[l] == nums[l+1]) ++l; // Skip duplicate nums[l]
                    ++l; --r;
                } else if (nums[l] + nums[r] > target) {
                    --r; // Decrease sum
                } else {
                    ++l; // Increase sum
                }
            }
        }
        while (l < r) {
            path.push_back(nums[l]);
            dfs(nums, l+1, r, k-1, target-nums[l], path);
            path.pop_back();
            while (l+1 < r && nums[l] == nums[l+1]) ++l; // Skip duplicate nums[l]
            ++l;
        }
    }
};