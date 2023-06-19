class Solution {
private:
    void twoSum(vector<int>& nums, vector<vector<int>>& res, int target, int i){
        int l=i, r=nums.size()-1;
        while(l<r){
            int sum = nums[l] + nums[r];
            if(sum == target){
                vector<int> temp = {-target, nums[l], nums[r]};
                sort(temp.begin(), temp.end());
                res.push_back(temp);
                while(l<r && nums[l]==nums[l+1]){
                    l+=1;
                }
                
                while(r>l && nums[r] == nums[r-1]){
                    r-=1;
                }
                
                l+=1;
                r-=1;
            } else if(sum > target){
                r-=1;
            } else {
                l+=1;
            }
        }
        
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=0;
        vector<vector<int>> res;
        
        while(left<nums.size()){
            twoSum(nums, res, -nums[left], left+1);
            while(left < nums.size()-1 && nums[left] == nums[left+1]){
                left+=1;
            }
            left+=1;
        }
        
        return res;
    }
};