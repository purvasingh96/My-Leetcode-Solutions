class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> psum(k, 0);
        psum[0]=1;
        
        int ps=0, res=0;
        
        for(int i=0;i<nums.size();i++){
            
            ps = (ps+nums[i])%k;
            if(ps<0) ps+=k;
            
            res += psum[ps];
            psum[ps]+=1;
        }
        
        return res;
        
    }
};