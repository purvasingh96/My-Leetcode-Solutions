class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long up=0, down=0;
        
        if(k==0){
            if(nums1==nums2) return 0;
            return -1;
        }
        
        for(int i=0;i<nums1.size();i++){
            int t = abs(nums1[i]-nums2[i]);
            if(t%k!=0) return -1;
            
            if(nums1[i] > nums2[i]) down += t/k;
            else up += t/k;
        }
        
        return up==down ? up: -1;
    }
};