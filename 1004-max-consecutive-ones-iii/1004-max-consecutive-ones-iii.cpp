class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0;
        vector<int> count(2, 0);
        int ans=0;
        
        for(;r<nums.size();r++){
            count[nums[r]]+=1;
            if(count[0] <= k){
                ans = max(ans, r-l+1);
            }
            
            if(count[0] > k){
                while(l<r && count[0]>k){
                    count[nums[l]]-=1;
                    l+=1;
                }
            }
        }
        
        return ans;
    }
};