class NumArray {
private:
    int n;
    vector<int> seg;
    
    void buildSegTree(vector<int>& nums, int idx, int left, int right) {
        if(left==right){
            seg[idx] = nums[left];
            return;
        }
        
        int mid = left + (right-left)/2;
        buildSegTree(nums, 2*idx+1, left, mid);
        buildSegTree(nums, 2*idx+2, mid+1, right);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void updateUtil(int root_idx, int left, int right, int idx, int val){
        
        // no overlap
        if(idx>right || idx < left) return;
        
        // total overlap
        if(left==right){
            if(left==idx){
                seg[root_idx] = val;
            }
            return;
        }
        
        // partial overlap
        int mid = left + (right-left)/2;
        
        updateUtil(2*root_idx+1, left, mid, idx, val);
        updateUtil(2*root_idx+2, mid+1, right, idx, val);
        
        seg[root_idx] = seg[2*root_idx+1] + seg[2*root_idx+2];
    }
    
    int queryUtil(int root_idx, int left, int right, int qleft, int qright){
        
        // total overlap
        if(left >= qleft && right<=qright){
            return seg[root_idx];
        }
        // no overlap
        if(left>qright || right<qleft){
            return 0;
        }
        
        // partial overlap
        int mid = left + (right-left)/2;
        int l = queryUtil(2*root_idx+1, left, mid, qleft, qright);
        int r = queryUtil(2*root_idx+2, mid+1, right, qleft, qright);
        
        return l+r;
        
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        buildSegTree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateUtil(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryUtil(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */