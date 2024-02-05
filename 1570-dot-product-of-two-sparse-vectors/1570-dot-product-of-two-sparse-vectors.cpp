class SparseVector {
public:
    map<int, int> m;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                m[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int prod=0;
        for(auto x:vec.m){
            if(m.find(x.first)!=m.end()){
                prod += (m[x.first] * x.second);
            }
        }
        
        return prod;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);