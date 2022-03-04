class SparseVector {
public:
    map<int, int> m;
    int n;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                m[i] = nums[i];
            }
        }
        n=nums.size();
    }
    
    int returnLen() {
        return n;
    }
    
    map<int, int> returnM() {
        return m;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res=0;
        map<int, int> vec_map = vec.returnM();
        
        for(int i=0;i<m.size();i++) {
            if(m[i]!=0 && vec_map[i]!=0) {
                res+= (m[i] * vec_map[i]);
            }
        }
        
        return res;
     
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);