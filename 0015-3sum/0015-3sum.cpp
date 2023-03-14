class Solution {
private:
    void dfs(int n, int left, int right, int target, vector<vector<int>>& res, vector<int>& temp, vector<int>& nums){
        if(n==2){
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    left+=1;
                    right-=1;
                    while(left<right && nums[left]==nums[left-1]) {
                        left+=1;
                    }
                } else if(sum > target) {
                    right-=1;
                } else {
                    left+=1;
                }
            }
        }
        
        
        while(left<right){
            temp.push_back(nums[left]);
            dfs(n-1, left+1, right, target-nums[left], res, temp, nums);
            temp.pop_back();
            while(left<right && nums[left] == nums[left+1]){
                left+=1;
            }
            left+=1;
        }
        
        
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        int n= nums.size();
        dfs(3, 0, n-1, 0, res, temp, nums);
        return res;
    }
};