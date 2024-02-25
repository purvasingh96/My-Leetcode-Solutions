class Solution {
private:
   void twoSum(vector<int>& nums, int start, int end, int target, set<vector<int>>& res){
         
        while(start<end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                res.insert({-target, nums[start], nums[end]});
                
                while(start < end && nums[start] == nums[start+1]){
                    start+=1;
                }
                
                while(start<end && nums[end] == nums[end-1]){
                    end-=1;
                }
                
                start+=1;
                end-=1;
                
            }
            
            else if(sum > target){
                while(start<end && nums[end] == nums[end-1]){
                    end-=1;
                }
                end-=1;
            } else {
                while(start<end && nums[start] == nums[start+1]){
                    start+=1;
                }
                start+=1;
            }
        }
        
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<nums.size();i++){
            int start = i, end = nums.size()-1;
            int target = -nums[start-1];
            twoSum(nums, start, end, target, res);
        }
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};