class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int prefix=0, c=0;
        
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(prefix == k) c+=1;
            
            
            int target = prefix-k;
            if(m.find(target)!=m.end()){
                c += m[target];
            }
            
            m[prefix]+=1;
            
        }
        
        return c;
        
    }
};