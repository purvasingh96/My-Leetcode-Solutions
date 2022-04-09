class Solution {
private:
    vector<int> unique;
    map<int, int> m;
public:
    int partition(int left, int right, int pivot_idx) {
        
        int pivot_freq = m[unique[pivot_idx]];
        
        swap(unique[pivot_idx], unique[right]);
        
        int store_idx = left;
        
        for(int i=left;i<=right;i++) {
            
            if(m[unique[i]] < pivot_freq) {
                
                swap(unique[store_idx], unique[i]);
                store_idx += 1;
                
            }
            
        }
        
        swap(unique[right], unique[store_idx]);
        return store_idx;
        
    }
    
    void quickSelect(int left, int right, int k) {
        
        if(left == right) return;
        
        int pivot_idx = left + rand()%(right - left +1);
        
        pivot_idx = partition(left, right, pivot_idx);
        
        if(pivot_idx == k) return;
        else if (pivot_idx < k) {
            
            quickSelect(pivot_idx+1, right, k);
            
        } else {
            quickSelect(left, pivot_idx-1, k);
        }
        
    }
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        for(auto x:nums) m[x] += 1;
        for(auto it:m) {
            unique.push_back(it.first);
        }
        cout<<m.size();
        int n = m.size();
        
        quickSelect(0, n-1, n-k);
        
        
        vector<int> top_k_frequent;
        
        for(int i=n-k;i<n;i++) {
            top_k_frequent.push_back(unique[i]);
        }
        //copy(unique.begin() + n - k, unique.end(), top_k_frequent.begin());
        
        return top_k_frequent;
        
    }
};