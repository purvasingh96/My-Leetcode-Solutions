class Solution {
public:
    vector<int> prefixSum;
    
    Solution(vector<int>& w) {
        srand((unsigned)time(0)); 
        
        prefixSum.push_back(w[0]);
        
        for(int i=1;i<w.size();i++) {
            int cur_sum = prefixSum.back() + w[i];
            this->prefixSum.push_back(cur_sum);
        }

    }

    
    int pickIndex() {
        
        int rand_num = rand()%prefixSum.back();
        
        int left=0, right=prefixSum.size()-1;
        
        return upper_bound(prefixSum.begin(), prefixSum.end(), rand_num) - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */