class Solution {
private:
    void twoSum(vector<int>& nums, int start, int end, int target, set<vector<int>>& ans){
        while(start<end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                ans.insert({-target, nums[start], nums[end]});
                while(start<end && nums[start] == nums[start+1]){
                    start+=1;
                }
                while(end>start && nums[end] == nums[end-1]){
                    end-=1;
                }
                start+=1;
                end-=1;
            } else if(sum > target){
                while(end>start && nums[end] == nums[end-1]){
                    end-=1;
                }
                end-=1;
            } else if(sum < target) {
                while(start<end && nums[start] == nums[start+1]){
                    start+=1;
                }
                start+=1;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        
        for(int i=0;i<n-1;i++){
            twoSum(nums, i+1, n-1, -nums[i], ans);
        }
        
        for(auto x:ans){
            res.push_back(x);
        }
        
        return res;
    }
};