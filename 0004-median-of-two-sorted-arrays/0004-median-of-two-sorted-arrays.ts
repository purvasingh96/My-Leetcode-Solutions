function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let m:number= nums1.length;
    let n: number= nums2.length;
    
    if(m>n) return findMedianSortedArrays(nums2, nums1);
    
    let l: number = 0;
    let r: number = m;
    
    while(l<=r){
        let mid: number = l + Math.floor((r-l)/2);
        let px: number = mid;
        let py: number = Math.floor((m+n+1)/2) - px;
        
        let maxLeftX: number = px==0?Number.MIN_SAFE_INTEGER:nums1[px-1];
        let minRightX: number = px==m?Number.MAX_SAFE_INTEGER:nums1[px];
        
        let maxLeftY: number = py==0?Number.MIN_SAFE_INTEGER:nums2[py-1];
        let minRightY: number = py==n?Number.MAX_SAFE_INTEGER:nums2[py];
        
        if(maxLeftX<=minRightY && maxLeftY<=minRightX){
            if((m+n)%2==0){
                return (Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2.000;
            } else {
                return Math.max(maxLeftX, maxLeftY);
            }
        }
        
        else if(maxLeftX > minRightY){
            r=px-1;
        } else l = px+1;
        
    }
    
    return -1.0000;
    
};