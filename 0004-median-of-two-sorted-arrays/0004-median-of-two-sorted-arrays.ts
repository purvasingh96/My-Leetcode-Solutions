function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let m = nums1.length;
    let n = nums2.length;
    
    if(m>n) return findMedianSortedArrays(nums2, nums1);
    
    let l=0, r=m;
    
    while(l<=r){
        let px = l + Math.floor((r-l)/2);
        let py = Math.floor((m+n+1)/2) - px;
        
        let maxLeftX = px==0 ? Number.MIN_SAFE_INTEGER: nums1[px-1];
        let minRightX = px==m? Number.MAX_SAFE_INTEGER : nums1[px];
        
        let maxLeftY = py==0 ? Number.MIN_SAFE_INTEGER : nums2[py-1];
        let minRightY = py==n ? Number.MAX_SAFE_INTEGER : nums2[py];
        
        if(maxLeftX <=minRightY && maxLeftY<=minRightX){
            if((m+n)%2==0){
                return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2.000;
            } else {
                return Math.max(maxLeftX, maxLeftY);
            }
            
        } else if(maxLeftX > minRightY){
            r = px-1;
        } else l = px+1;
        
    }
    return -1.0000;
    
};