class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        // OE
        if(n1%2!=0 && n2%2==0){
            int ans=nums2[0];
            for(int i=1;i<n2;i++) ans^=nums2[i];
            return ans;
        }
        
        // EO
        else if(n1%2==0 && n2%2!=0){
            int ans=nums1[0];
            for(int i=1;i<n1;i++) ans^=nums1[i];
            return ans;
        }
        
        // OO
        else if(n1%2!=0 && n2%2!=0){
            int ans=nums1[0];
            for(int i=1;i<n1;i++) ans^=nums1[i];
            for(int i=0;i<n2;i++) ans^=nums2[i];
            return ans;
        }
        
        // EE
        return 0;
        
    }
};