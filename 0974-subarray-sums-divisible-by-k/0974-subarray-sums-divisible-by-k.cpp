class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ps = 0, n = nums.size(), res=0;
        m[0]=1;
        
        for(int i=0;i<n;i++){
            ps += nums[i];
            int mod_val = (ps%k + k)%k;
            
            res += m[mod_val];
            m[mod_val]+=1;
        }
        
        return res;
        
    }
};