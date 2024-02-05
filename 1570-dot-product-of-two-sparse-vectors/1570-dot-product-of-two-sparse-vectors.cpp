class SparseVector {
public:
    vector<int> m;
    SparseVector(vector<int> &nums) {
        m.resize(nums.size(), -1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int prod=0;
        for(int i=0;i<vec.m.size();i++){
            if(vec.m[i]!=-1 && m[i]!=-1){
                prod += (m[i] * vec.m[i]);
            }
        }
        
        return prod;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);