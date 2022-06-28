class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        if(k==nums.size()) return accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> lr(n);
        
        lr[0] = nums[0];
        
        
        for(int i=1;i<n;i++){
            lr[i] = lr[i-1]+nums[i];
        }
        
       int left=-1, right=n-k-1;
       
        int maxsum=INT_MIN, total_sum=lr.back();
        
        while(right<n){
            
            int diff = lr[right];
            if(left!=-1){
                diff = lr[right] - lr[left];
            }
            
            maxsum = max(maxsum, (total_sum - diff));
            right+=1;
            left+=1;
            
        }
        
        return maxsum;
        
    }
};