class Solution {
private:
    int partitionAndSort(int left, int right, int pivot_idx, unordered_map<int, int>& freq, vector<int>& res){
        
        int store_idx = left;
        int pivot_freq = freq[res[pivot_idx]];
        swap(res[pivot_idx], res[right]);
        
        for(int i=left;i<=right;i++){
            if(freq[res[i]] < pivot_freq){
                swap(res[i], res[store_idx]);
                store_idx+=1;
            }
        }
        
        swap(res[store_idx], res[right]);
        return store_idx;
        
    }
    
    void quickSelect(int left, int right, int k_smallest, unordered_map<int, int>& freq, vector<int>& res){
        int pivot_idx = left + rand()%(right-left+1);
        pivot_idx = partitionAndSort(left, right, pivot_idx, freq, res);
        
        if(pivot_idx == k_smallest){
            return;
        }
        else if(pivot_idx > k_smallest){
            quickSelect(left, pivot_idx-1, k_smallest, freq, res);
        } else {
            quickSelect(pivot_idx+1, right, k_smallest, freq, res);
        }
        
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // quick select implementation
        unordered_map<int, int> freq;
        vector<int> res;
        for(auto x:nums) freq[x]+=1;
        for(auto x:freq){
            res.push_back(x.first);
        }
        
        int n = res.size();
        quickSelect(0, n-1, n-k, freq, res);
        
        vector<int> ans;
        for(int i=n-k;i<n;i++) ans.push_back(res[i]);
        
        return ans;
        
    }
};