class Solution {

public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int sum=0;
        map<int, int> m;
        int n = nums.size();
        vector<long long> dp(n, 1);
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;
        
        for(int i=0;i<nums.size();i++) m[nums[i]] = i;
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                if(nums[i]%nums[j]==0){
                    
                    int target = nums[i]/nums[j];
                    
                    if(m.find(target)!=m.end()){
                        
                        long long comb = dp[m[target]]*dp[j];
                        comb = comb%mod;
                        dp[i]+= comb;
                        
                    }
                }
                
            }
            
        }
        long long ans = accumulate(dp.begin(), dp.end(), 0L);
        
        return (int)(ans%mod);
    }
};