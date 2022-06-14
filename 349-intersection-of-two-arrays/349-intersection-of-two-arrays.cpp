class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        
        int it1=0, it2=0;
        
        while(it1!=m && it2!=n){
            
            if(nums1[it1] == nums2[it2]){
                res.push_back(nums1[it1]);
                while(it1<m-1 && nums1[it1] == nums1[it1+1]){
                    it1+=1;
                }
                
                while(it2<n-1 && nums2[it2] == nums2[it2+1]){
                    it2+=1;
                }
                
                it1+=1;
                it2+=1;
                
            } else if(nums1[it1] < nums2[it2]){
                it1+=1;
            } else{
                it2+=1;
            }
            
        }
        
        return res;
        
    }
};