class Solution {
private:
    int backtrack(int idx, int k, vector<int>& nums, vector<int>& temp){
        if(idx>=nums.size()) return 0;
        
        int ans=0;
        int take=0;
        int notTake = backtrack(idx+1, k, nums, temp);
        
        if(binary_search(temp.begin(), temp.end(), nums[idx] - k)==0){
            temp.push_back(nums[idx]);
            take = (1+backtrack(idx+1, k, nums, temp));
            temp.pop_back();
        }
        return take+notTake;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        return backtrack(0, k, nums, temp);
    }
};