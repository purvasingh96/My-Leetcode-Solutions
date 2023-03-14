class Solution {
private:
    void dfs(int k, long long target, int l, int r, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(k==2){
            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    while(l+1<r && nums[l] == nums[l+1]) l+=1;
                    l+=1;
                    r-=1;
                } else if(sum > target) r-=1;
                else l+=1;
            }
        }
        
        while(l<r){
            temp.push_back(nums[l]);
            dfs(k-1, target-nums[l], l+1, r, nums, temp, res);
            temp.pop_back();
            while(l+1<r && nums[l] == nums[l+1]) l+=1;
            l+=1;
        }
        
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        int n =nums.size();
        dfs(4, target, 0, n-1, nums, temp, res);
        return res;
    }
};