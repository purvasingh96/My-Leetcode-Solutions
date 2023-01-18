class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // kandane algo
        int ts = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int gmax=nums[0], gmin=nums[0], localmax=nums[0], localmin=nums[0], gmaxc=nums[0], gans=nums[0];
        
        for(int i=1;i<n;i++){
            localmax = max(nums[i], localmax+nums[i]);
            localmin = min(nums[i], localmin+nums[i]);
            
            gmin = min(gmin, localmin);
            gmax = max(gmax, localmax);
            if(i!=n-1) gmaxc = max(gmaxc, ts-gmin);
            
            gans = max(gans, max(gmax, gmaxc));
        }
        
        return gans;
    }
};