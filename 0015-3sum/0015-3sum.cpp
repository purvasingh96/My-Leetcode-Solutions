class Solution {
private:
    void dfs(int k, int target, int l, int r, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        if(k == 2){
            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    while(l+1<r && nums[l]==nums[l+1]) {
                        l+=1;
                    }
                    l+=1;
                    r-=1;
                } else if(sum > target) r-=1;
                else l+=1;
            }
        }
        
        while(l<r){
            temp.push_back(nums[l]);
            dfs(k-1, target-nums[l], l+1, r, temp, ans, nums);
            temp.pop_back();
            while(l+1<r && nums[l] == nums[l+1]) l+=1;
            l+=1;
        }
        
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        int n = nums.size();
        dfs(3, 0, 0, n-1, temp, res, nums);
        return res;
    }
};