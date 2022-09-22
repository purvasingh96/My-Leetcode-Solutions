class Solution {
private:
    vector<int> seg;
public:
    void buildTree(vector<int>& nums, int start, int end, int idx){
        if(start==end){
            seg[idx] = nums[start]%2==0 ? nums[start]:0;
            return;
        }
        int mid = start + (end-start)/2;
        
        buildTree(nums, start, mid, 2*idx+1);
        buildTree(nums, mid+1, end, 2*idx+2);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        
    }
    
    void update(int start, int end, int idx, int val, int i){
        if(i<start || i>end){
            return;
        }
        
        if(start==end){
            seg[idx] = val%2==0?val:0;
            return;
        }
        
        int mid = start + (end-start)/2;
        
        if(start<=i && i<=mid) update(start, mid, 2*idx+1, val, i);
        else update(mid+1, end, 2*idx+2, val, i);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        seg.resize(4*n);
        
        vector<int> res;
        buildTree(nums, 0, n-1, 0);
        
        for(auto q:queries){
            int val=q[0], index=q[1];
            nums[index] += val;
            update(0, n-1, 0, nums[index], index);
            res.push_back(seg[0]);
        }
        
        return res;
    }
};