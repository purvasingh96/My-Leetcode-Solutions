class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
public:
    // total time complexity = Nlogk + Mlogk
    // space complexity = O(k)
    
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        // nlogk
        for(auto x:nums) {
            
            add(x);
        }
    }
    
    // making M calls to add => Mlogk
    
    int add(int val) {
        // log k operation
        pq.push(val);
        if(pq.size()>kth) pq.pop();
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */