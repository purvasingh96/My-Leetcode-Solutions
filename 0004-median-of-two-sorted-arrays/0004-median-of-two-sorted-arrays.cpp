class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l =0, r=m;
        
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            int pX = mid;
            int pY = (m+n+1)/2 - pX;
            
            int maxLeftX = pX==0?INT_MIN:nums1[pX-1];
            int minRightX = pX==m?INT_MAX:nums1[pX];
            
            int maxLeftY = pY==0?INT_MIN:nums2[pY-1];
            int minRightY = pY==n?INT_MAX:nums2[pY];
            
            if(maxLeftX <= minRightY && maxLeftY<=minRightX){
                if((m+n)%2==0){
                    // even
                    return  (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.00;
                    
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if(maxLeftX > minRightY){
                r = pX-1;
            } else {
                l = pX+1;
            }
            
        }
        
        return -1.000;
    }
};