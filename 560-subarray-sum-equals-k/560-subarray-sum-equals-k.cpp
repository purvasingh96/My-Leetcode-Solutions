class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int res=0;
        map<int, int> m;
        int prefix_sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            
            m[prefix_sum]+=1;
            
            prefix_sum += nums[i];
            
            if(m.find(prefix_sum - k)!=m.end()) {
                
                res += m[prefix_sum - k];
                
            }
                
            
        }
        
        return res;
        
    }
};