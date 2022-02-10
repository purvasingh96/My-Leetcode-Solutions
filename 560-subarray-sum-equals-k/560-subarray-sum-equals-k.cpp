class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int res=0;
        map<int, int> m;
        
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        
        for(int i=0;i<nums.size();i++) {
            
            if(nums[i] == k) res+=1;
                
              if(m.find((nums[i] - k))!=m.end()) {
                  
                  res += m[(nums[i] - k)];
                  
              }
            
            m[nums[i]] += 1;
                
            
        }
        
        return res;
        
    }
};