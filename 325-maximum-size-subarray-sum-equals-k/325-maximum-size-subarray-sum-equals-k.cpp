class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int prefixSum = 0, max_len=0;
        
        map<int, int> m;
        
        for(int i=0;i<nums.size();i++) {
            
            prefixSum += nums[i];
            
            if(prefixSum == k) {
                max_len = i+1;
            }
            
            if(m.find(prefixSum-k)!=m.end()) {
                
                max_len = max(max_len,  (i-m[prefixSum-k]));
                
            }
            
            if(m.find(prefixSum) == m.end()) {
                
                m[prefixSum] = i;
                
            }
            
        }
        
        return max_len;
    }
};