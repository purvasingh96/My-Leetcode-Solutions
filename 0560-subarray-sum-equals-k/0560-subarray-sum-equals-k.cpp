class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> m;
        int currPs=0, res=0;
        m[0]=1;
        for(auto x:nums){
            currPs += x;
            if(m.find(currPs - k)!=m.end()){
                res+= m[currPs-k];
            }
            m[currPs]+=1;
        }
        
        return res;
    }
};