class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long prefixSum =0;
        int ans=0;
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(prefixSum == k) ans = i+1;
            
            else {
                if(m.find(prefixSum - k)!=m.end()){
                    ans = max(ans, i-m[prefixSum - k]);
                }
            }
            
            if(m.find(prefixSum) == m.end()){
                m[prefixSum] = i;
            }
        }
        
        return ans;
    }
};