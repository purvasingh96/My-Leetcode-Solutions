class NumArray {
private:
    int n;
    vector<int> seg;
    
    void buildTree(vector<int>& nums, int ind, int left, int right) {
		if (left == right) {
			seg[ind] = nums[left];
			return;
		}
		int mid = (left + right) / 2;
		buildTree(nums, 2 * ind + 1, left, mid);
		buildTree(nums, 2 * ind + 2, mid + 1, right);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
    
    int query(int root_idx, int low, int high, int qlow, int qhigh){
        
        //total overlap
        if(low>=qlow && high<=qhigh){
            return seg[root_idx];
        }
        
        // no overlap
         if(qlow>high || qhigh <low){
            return 0;
        }
        
        // partial overlap
        
            int mid = low + (high-low)/2;
            
            int left = query(2*root_idx+1, low, mid, qlow, qhigh);
            int right = query(2*root_idx+2, mid+1, high,  qlow, qhigh);
            
            return left+right;
        
    }
    
    void updateUtil(int ind, int left, int right, int index, int val) {
		// no overlap
		if (index < left || index > right) return;

		// total overlap
		if (left == right) {
			if (left == index)
				seg[ind] = val;
			return;
		}

		// partial overlap
		int mid = (left + right) / 2;
		updateUtil(2 * ind + 1, left, mid, index, val); // left child
		updateUtil(2 * ind + 2, mid + 1, right, index, val); // right child
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n, 0);
        buildTree(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        if (n == 0) return;
        updateUtil(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */