class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]=1;
        int sum=0;
        int res=0;
        
        for(auto c:nums){
            sum += c;
            if(m.find(sum-k) != m.end()){
                res += m[sum-k];
            }
            m[sum] += 1;
        }
        
        return res;
    }
};