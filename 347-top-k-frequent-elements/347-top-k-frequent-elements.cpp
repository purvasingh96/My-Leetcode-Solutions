class Solution {
private:
    vector<int> unique;
    map<int, int> count_map;
public:
    // Quick Select
    // partition
    int partition(int left, int right, int pivot_idx) {
        
        int pivot_freq = count_map[unique[pivot_idx]];
        
        swap(unique[pivot_idx], unique[right]);
        int store_idx = left;
        
        for(int i=left;i<=right;i++) {
            
            if(count_map[unique[i]] < pivot_freq) {
                
                swap(unique[i], unique[store_idx]);
                store_idx += 1;
                
            }
            
        }
        
        swap(unique[right], unique[store_idx]);
        return store_idx;
        
    }
    
    void quickSelect(int left, int right, int k) {
        
        if(left == right) return;
        
        int pivot_idx = left + rand()%(right-left+1);
        
        pivot_idx = partition(left, right, pivot_idx);
        
        if(pivot_idx == k) return;
        else if(k < pivot_idx) {
            quickSelect(left, pivot_idx-1, k);
        } else {
            quickSelect(pivot_idx+1, right, k);
        }
        
    }
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(auto x:nums) count_map[x]+=1;
        
        for(auto x:count_map) {
            unique.push_back(x.first);
        }
        
        int n = count_map.size();
        
        quickSelect(0, n-1, n-k);
        
        vector<int> topk(k);
        
        copy(unique.begin() + n-k, unique.end(), topk.begin());
        
        return topk;
        
        
    }
};