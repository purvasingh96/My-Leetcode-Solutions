class Solution {
private:
    int kandane(vector<int>& nums1, vector<int>& nums2){
        int lsum =0, gsum=0, sum=0;
        
        for(int i=0;i<nums1.size();i++){
            sum = max(nums2[i]-nums1[i], sum+nums2[i]-nums1[i]);
            gsum = max(gsum, sum);                
        }
        
        return gsum;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(accumulate(nums1.begin(), nums1.end(), 0) + kandane(nums1, nums2),
                  accumulate(nums2.begin(), nums2.end(), 0) + kandane(nums2, nums1));
        
        
    }
};