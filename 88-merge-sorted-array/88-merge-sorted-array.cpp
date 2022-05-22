class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        - copy nums2 to nums1 where 0s are present O(n)
        - left=0, right=n;
        - while(left<n && right<(m+n))
            - if n[left] > n[right]: swap them and 
            
        */
        
        int p1=m-1, p = (m+n-1), p2=n-1;
        
        for(p;p>=0;p--){
            if(p2<0) break;
            if(p1>=0 && nums1[p1] > nums2[p2]){
                nums1[p]=nums1[p1];
                
                p1--;
            } else{
                nums1[p]=nums2[p2];
                
                p2--;
            }
            
        }
        
        
    }
    
};