class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int l=0, r=0;
        long long sum=0;
        int ans=0;
        sort(nums.begin(), nums.end());
        
        for(;r<nums.size();r++){
            sum += (long long)nums[r];
            long long prod = (long long)(nums[r])*(long long)(r-l+1);
            
            if(prod - sum > k){
                
                while(l<r && prod - sum > k){
                    sum-=(long long)nums[l];
                    l+=1;
                    prod = (long long)(nums[r])*(long long)(r-l+1);
                }
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
        
    }
};