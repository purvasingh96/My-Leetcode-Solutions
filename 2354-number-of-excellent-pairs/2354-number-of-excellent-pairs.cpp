class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> nums_set(nums.begin(), nums.end());
        long long ans=0;
        vector<int> setbits;
        
        for(auto x:nums_set){
            
            setbits.push_back(__builtin_popcount(x));
        }
        
        sort(setbits.begin(), setbits.end());
        
        for(int i=0;i<setbits.size();i++){
            
            int p = k-setbits[i];
            
            auto it = lower_bound(setbits.begin(), setbits.end(), p);
            
            ans += (setbits.end() - it);
            
        }
        
        return ans;
    }
};