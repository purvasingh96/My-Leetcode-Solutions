class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        map<int, int> m;
        
        for(auto a:nums1) {
            for(auto b:nums2) {
                
                m[(a+b)] += 1;
            }
        }
        
        for(auto c:nums3) {
            for(auto d:nums4) {
                
                int target = - (c+d);
            
                if(m.find(target) != m.end()) {
                    
                    count += m[target];
                    
                }
                
            }
        }
        
        return count;
    }
};