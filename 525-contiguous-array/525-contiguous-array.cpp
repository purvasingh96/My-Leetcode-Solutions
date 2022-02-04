class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m;
        int count=0, max_len=0;
        
        for(int i=0;i<nums.size();i++) {
            
            count += (nums[i]==1?1:-1);
            
            if(count==0) {
                
                max_len = max(max_len, i+1);
                
            }
            
            if(m.find(count)!=m.end()) {
                
                max_len = max(max_len, i-m[count]);
                
            } else {
                
                m[count] = i;
                
            }
            
        }
        
        return max_len;
    }
};