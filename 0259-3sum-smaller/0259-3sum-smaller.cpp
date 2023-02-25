class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t = target - (nums[i] + nums[j]);
                int idx = lower_bound(nums.begin()+j+1, nums.end(), t) - nums.begin();
                ans += (idx-j-1);
            }
        }
        
        return ans;
        
    }
};