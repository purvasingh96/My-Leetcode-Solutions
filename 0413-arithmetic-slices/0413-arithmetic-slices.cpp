class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int l=0, r=1;
        int ans=0, i=1, diff = nums[1] - nums[0];
        int n = nums.size();
        
        while(i<n){
            if(nums[i] - nums[i-1] == diff){
                if(i-l+1==3) r=i;
                if(i-l+1>=3){
                    ans += (i-r+1);
                }
                i+=1;
            } else {
                l=i-1;
                diff = nums[i]-nums[i-1];
            }
        }
        return ans;
        
    }
};