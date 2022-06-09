class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int left=0, right=nums.size()-1;
        
        while(left<right){
            
            int sum = nums[left]+nums[right];
            
            if(sum == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            } else if(sum > target){
                right-=1;
            } else{
                left+=1;
            }
            
        }
        
        return res;
    }
};