class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l = 0, r=0;
        long long ans=0;
        int i=0, n = nums.size();
        while(i<n){
            if(nums[i]!=0) i+=1;
            else {
                int l=i, r=i;
                while(i<n && nums[i]==0){
                    ans += (r-l+1);
                    r+=1;
                    i+=1;
                }
            }
        }
        return ans;
    }
};