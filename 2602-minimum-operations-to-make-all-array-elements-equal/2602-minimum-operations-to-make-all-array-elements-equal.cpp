class Solution {

public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> ps;
        long long n = nums.size();
        ps.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            ps.push_back((ps.back() + nums[i]));
        }
        vector<long long> res;
        
        for(long long q:queries){
    
            int idx = prev(upper_bound(nums.begin(), nums.end(), q)) - nums.begin();
            
            long long left=0, right=0;
            
            if(idx<0) right = ps.back() -  (long long)(q*n);
            else {
                left = (q*(idx+1)) - ps[idx];
                right = (ps.back() - ps[idx]) - (q*(n - (idx+1)));
            }
            
            res.push_back(left+right);
            
        }
        
        return res;
        
    }
};