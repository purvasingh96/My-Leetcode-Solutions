class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        map<int, int> m;
        
        int prefixsum = 0;
        m[0] = -1;
        
        for(int i=0;i<nums.size();i++) {
            
            prefixsum += nums[i];
            
            prefixsum %=k;
            
            
            
            if(m.find(prefixsum)!=m.end()) {
                
                if(i - m[prefixsum] > 1) return true;
                
            }
            
            else m[prefixsum] = i;
            
        }
        
        return false;
        
    }
};