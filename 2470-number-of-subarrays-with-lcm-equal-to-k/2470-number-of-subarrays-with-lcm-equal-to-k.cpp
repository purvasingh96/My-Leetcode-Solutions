class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            int res = nums[i];
            if(res == k) count+=1;
            for(int j=i+1;j<nums.size();j++){
                res = lcm(res, nums[j]);
                if(res == k) count+=1;
                if(res > k) break;
            }
        }
        
        return count;
    }
};