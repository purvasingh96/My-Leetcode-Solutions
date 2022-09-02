class SegmentTree{
public:
    vector<int> tree;
    int n;
    SegmentTree(int n){
        this->n = n;
        tree.resize(4*n);
    }
    
    int left(int node) {
        return 2*node+1;
    }
    
    int right(int node){
        return 2*node+2;
    }
    
    void update(int node, int start, int end, int val){
        if(start>end) return;
        if(start == end) {
            tree[node]+=1;
            return;
        }
        
        int mid = start + (end-start)/2;
        if(val <=mid) update(left(node), start, mid, val);
        else update(right(node), mid+1, end, val);
        
        tree[node] = tree[left(node)] + tree[right(node)];
    }
    
    int query(int node, int s, int e, int qs, int qe){
        if(s>e || qs>e || qe<s) return 0;
        if(s>=qs && e<=qe) return tree[node];
        
        int mid = s + (e-s)/2;
        int l = query(left(node), s, mid, qs, qe);
        int r = query(right(node), mid+1, e, qs, qe);
        
        return l+r;
        
    }
};

class Solution {
private:
    void convert(vector<int>& nums){
        int val = 1e4+1;
        for(int i=0;i<nums.size();i++) nums[i] += val;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        convert(nums);
        int maxval = *max_element(nums.begin(), nums.end());
        SegmentTree* st = new SegmentTree(maxval+1);
        int n = nums.size();
        vector<int> ans(n, 0);
        
        for(int i=n-1;i>=0;i--){
            st->update(0, 0, maxval, nums[i]);
            int l=0, r=nums[i]-1;
            ans[i] = st->query(0, 0, maxval, l, r);
        }
        
        return ans;
    }
};