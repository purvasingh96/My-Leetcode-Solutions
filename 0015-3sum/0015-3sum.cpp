class Solution {
private:
    void twoSum(vector<int>& nums, int target, int start, set<vector<int>>& res){
        int i=start, j=nums.size()-1;
        
        while(i<j){
            int sum = nums[i] + nums[j];
            
            if(sum > target){
                while(j>i && nums[j] == nums[j-1]){
                    j-=1;
                }
                j-=1;
            }
            
            else if(sum < target){
                while(i<j && nums[i] == nums[i+1]){
                    i+=1;
                }
                i+=1;
            }
            
            else if(sum == target){
                vector<int> temp = {-target, nums[i], nums[j]};
                res.insert(temp);
                while(j>i && nums[j] == nums[j-1]){
                    j-=1;
                }
                while(i<j && nums[i] == nums[i+1]){
                    i+=1;
                }
                
                i+=1;
                j-=1;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int start=1;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        while(start<nums.size()){
            twoSum(nums, -nums[start-1], start, res);
            start+=1;
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};