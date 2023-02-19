class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int low=0, high=m;
        
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        /*                      *(partition)
         X = 23, 26(maxLeftX), |56(minRightX), 59
         Y = 1,  2, 5(maxLeftY)| 8(minRightY), 90
        
        */
        
        while(low<=high){
            int partitionX = low + (high-low)/2;
            int partitionY = (m+n+1)/2 - partitionX;
            
            int maxLeftX = partitionX==0 ? INT_MIN : nums1[partitionX-1];
            int minRightX = partitionX==m ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = partitionY == 0 ? INT_MIN: nums2[partitionY-1];
            int minRightY = partitionY == n ? INT_MAX: nums2[partitionY];
            
            // found condition
            if(maxLeftX <= minRightY && maxLeftY<=minRightX){
                if((m+n)%2==0){
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2; 
                } else{
                    return (double)(max(maxLeftX, maxLeftY));
                }
            }
            
            else if(maxLeftX > minRightY){
                high = partitionX-1;
            } else low = partitionX+1;
    }
        
        return -1;
    }
        
};