class NumArray {
private:
    vector<int> input;
    int n;
    vector<int> tree;
    
  
    void treeBuilder(int idx, int left, int right, vector<int>& tree, vector<int>& nums){
        if(left==right){
            tree[idx]=input[left];
            return;
        }
        
        int mid= left + (right-left)/2;
        treeBuilder(2*idx+1, left, mid, tree, nums);
        treeBuilder(2*idx+2, mid+1, right, tree, nums);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    
    void updateTree(vector<int>& input, int idx, int val, int pos, int left, int right){
        if(idx<left || idx>right) return;
        if(left == right && left == idx){
            tree[pos]=val;
            return;
        }
        
        int mid = left + (right-left)/2;
        updateTree(input, idx, val, 2*pos+1, left, mid);
        updateTree(input, idx, val, 2*pos+2, mid+1, right);
        tree[pos] = tree[2*pos+1] + tree[2*pos+2];
        
    }
    
    int queryUtil(vector<int>& input, int qleft, int qright, int pos, int left, int right){
        // total overlap
        if(qleft<=left && right<=qright){
            return tree[pos];
        }
        
        // no overlap
        if(qleft>right || qright<left){
            return 0;
        }
        
        int mid = left + (right-left)/2;
        
        int l = queryUtil(input, qleft, qright, 2*pos+1, left, mid);
        int r = queryUtil(input, qleft, qright, 2*pos+2, mid+1, right);
        
        return (l+r);
    }
    
public:
    
    NumArray(vector<int>& nums) {
        
        n = nums.size();
        tree.resize(4*n, 0);
        
        input=nums;
        treeBuilder(0, 0, n-1, tree, input);
    }
    
    void update(int index, int val) {
        updateTree(input, index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return queryUtil(input, left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */