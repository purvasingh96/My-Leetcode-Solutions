class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() < nums1.size()) {
            return intersect(nums2, nums1);
        }
        
        map<int,int> m;
        vector<int> res;
        
        for(auto n:nums1) {
            m[n]+=1;
        }
        
        for(auto n:nums2) {
            
            if(m.find(n)!=m.end()) {
                
                if(m[n] > 0) {
                    res.push_back(n);
                    m[n]-=1;
                }
                
            }
            
        }
        
        return res;
        
    }
};