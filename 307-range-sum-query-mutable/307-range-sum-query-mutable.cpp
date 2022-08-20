class NumArray {
private:
    int n;
    vector<int> seg;
    vector<int> nums;
    void buildTree(int idx, int left, int right, vector<int>& seg, vector<int>& nums){
        if(left == right){
            seg[idx] = nums[left];
            return;
        }
        
        int mid = left + (right-left)/2;
        buildTree(2*idx+1, left, mid, seg, nums);
        buildTree(2*idx+2, mid+1, right, seg, nums);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    int queryUtil(int root_idx, int left, int right, int qleft, int qright){
        if(qleft<=left && qright>=right){
            return seg[root_idx];
        }
        
        if(qleft>right || qright<left) return 0;
        
        int mid = left + (right-left)/2;
        
        int l = queryUtil(2*root_idx+1, left, mid, qleft, qright);
        int r = queryUtil(2*root_idx+2, mid+1, right, qleft, qright);
        
        return l+r;
    }
    
    void updateUtil(int root_idx, int left, int right, int idx, int val){
        if(idx<left || idx>right){
            return;
        }
        
        if(left == right){
            if(left == idx){
                seg[root_idx] = val;
            }
            return;
        }
        
        int mid = left + (right-left)/2;
        
        updateUtil(2*root_idx+1, left, mid, idx, val);
        updateUtil(2*root_idx+2, mid+1, right, idx, val);
        
        seg[root_idx] = seg[2*root_idx+1] + seg[2*root_idx+2];
        
    }
    
    
    
public:
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        nums = nums;
        buildTree(0, 0, n-1, seg, nums);
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